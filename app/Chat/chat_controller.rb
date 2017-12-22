require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'

class ChatController < Rho::RhoController
	include BrowserHelper
	include ApplicationHelper

	def init
		begin
			googleJSONFile = Rho::RhoFile.join(Rho::Application.publicFolder, "google-services.json")
			jsonData = File.read(googleJSONFile)
			firebaseConfig = Rho::JSON.parse(jsonData)

			google_api_key = firebaseConfig['client'][0]['api_key'][0]['current_key']
			google_app_id = firebaseConfig['client'][0]['client_info']['mobilesdk_app_id']
			gcm_sender_id = firebaseConfig['project_info']['project_number']
			google_project_id = firebaseConfig['project_info']['project_id']
			google_storage_bucket = firebaseConfig['project_info']['storage_bucket']
			dialogflow_client_access_token = "2e5449618aeb4756a64a09f413a16f87"
			dialogflow_language = "en"
		rescue Exception => e
			Rho::Log.error("Error in Firebase config file--->#{e}\n#{e.backtrace}", "ChatController")
		end
		objects = Rho::Chat.enumerate
		obj = objects[0]
		res = obj.init(google_api_key,google_app_id,gcm_sender_id,google_project_id,google_storage_bucket,dialogflow_client_access_token,dialogflow_language)
	end

	def sendMessage
		objects = Rho::Chat.enumerate
		obj = objects[0]
		res = obj.sendMessage(@params["query"])
		resultHash = Rho::JSON.parse(res.to_s)
		render :string => resultHash["result"]["fulfillment"]["speech"]
	end
end