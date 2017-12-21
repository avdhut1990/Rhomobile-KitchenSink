require 'rho/rhocontroller'
require 'helpers/application_helper'
require 'helpers/browser_helper'

class ChatController < Rho::RhoController
	include BrowserHelper
	include ApplicationHelper

	def index
		render :back => '/app'
	end

	def init
		objects = Rho::Chat.enumerate
		obj = objects[0]
		res = obj.init("AIzaSyA5ISHf11DwSlYPq-tDfClo-6A_tk9D6TQ","1:188430455636:android:a6db880f1f885a6c","188430455636","kitchensink-1718a","kitchensink-1718a.appspot.com") 
		Alert.show_popup "Rho::Chat.initreturn : #{res.to_s}"
	end
end