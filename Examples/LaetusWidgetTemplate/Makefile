THEOS_DEVICE_IP = localhost
THEOS_DEVICE_PORT = 2222

ARCHS = arm64 arm64e

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = LaetusWidgetTemplate
$(BUNDLE_NAME)_CFLAGS = -fobjc-arc
$(BUNDLE_NAME)_FILES = $(wildcard *.m)
$(BUNDLE_NAME)_FRAMEWORKS = UIKit
$(BUNDLE_NAME)_INSTALL_PATH = /Library/Laetus/Themes

include $(THEOS_MAKE_PATH)/bundle.mk

BUNDLE_PATH = $($(BUNDLE_NAME)_INSTALL_PATH)/$(BUNDLE_NAME).bundle

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)$(BUNDLE_PATH)$(ECHO_END)
	$(ECHO_NOTHING)cp Info.plist $(THEOS_STAGING_DIR)$(BUNDLE_PATH)/Info.plist$(ECHO_END)

after-install::
	install.exec "killall -9 backboardd"