#!/usr/bin/env python
from pbxproj import XcodeProject

# open the project
project = XcodeProject.load('project/iphone/KitchenSink.xcodeproj/project.pbxproj')

# file_options = FileOptions(weak=True)
project.add_file('extensions/chat/ext/platform/iphone/impl/Firebase/Auth/FirebaseAuth.framework', force=False)
project.add_file('extensions/chat/ext/platform/iphone/impl/Firebase/Analytics/FirebaseCoreDiagnostics.framework', force=False)
project.save()