#!/usr/bin/env python
import os

from glob import glob
from pbxproj import XcodeProject

framework_files = [y for x in os.walk("platform/iphone/impl/Firebase") for y in glob(os.path.join(x[0], '*.framework'))]

for file in os.listdir("../../../project/iphone"):
    if file.endswith(".xcodeproj"):
    	xcode_project = os.path.join(os.path.join("../../../project/iphone", file), "project.pbxproj")

print framework_files
print xcode_project

project = XcodeProject.load(xcode_project)
frameworkGroup = project.get_or_create_group('Frameworks')
for framework in framework_files:
	print "Processing :"+framework
	project.add_file(framework,
                     parent=frameworkGroup,
                     tree='SDKROOT',
                     weak=True, force=False)
project.save()



# FRAMEWORK_FILES=$(find -E platform/iphone/impl/Firebase -regex ".*\.(framework)")
# XCODE_PROJ=$(find -E ../../../project/iphone -maxdepth 1 -regex ".*\.(xcodeproj)")
# echo $XCODE_PROJ

# from pbxproj import XcodeProject

# # open the project
# project = XcodeProject.load($XCODE_PROJ+'/project.pbxproj')
# for f in $FRAMEWORK_FILES; do
# 	echo "Processing $f"
# 	# python -m pbxproj file --weak --no-embed "$XCODE_PROJ" "$f"
# 	project.add_file($f, force=False)
# 	wait
# done