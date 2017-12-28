include ../Makefile.tests_common

# name of your application
#APPLICATION = Jetbench

# If no BOARD is found in the environment, use this default:
#BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
#RIOTBASE ?= $(CURDIR)/../RIOT

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -g
CFLAGS += -DDEVELHELP
CFLAGS += -Werror=implicit-fallthrough=0

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

# Modules to include:
#USEMODULE += shell
#USEMODULE += shell_commands
USEMODULE += ps
USEMODULE += pthread
USEMODULE += xtimer

include $(RIOTBASE)/Makefile.include

test:
	tests/01-run.py