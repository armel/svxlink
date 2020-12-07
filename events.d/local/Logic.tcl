
#
# Generic Logic event handlers
#

#
# This is the namespace in which all functions and variables below will exist.
#
namespace eval Logic {

sourceTcl /usr/share/svxlink/events.d/local/LogicBeginRRF.inc

#
# Executed when a DTMF command has been received
#   cmd - The command
#
# Return 1 to hide the command from further processing is SvxLink or
# return 0 to make SvxLink continue processing as normal.
#
# This function can be used to implement your own custom commands or to disable
# DTMF commands that you do not want users to execute.

proc dtmf_cmd_received {cmd} {

  sourceTcl /usr/share/svxlink/events.d/local/LogicPlugInRRF.inc
  sourceTcl /usr/share/svxlink/events.d/local/LogicAnalogicRRF.inc
  sourceTcl /usr/share/svxlink/events.d/local/LogicNumericRRF.inc

  return 0
}

sourceTcl /usr/share/svxlink/events.d/local/LogicEndRRF.inc

}

#
# This file has not been truncated
#