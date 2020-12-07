
#
# Generic Logic event handlers
#

#
# This is the namespace in which all functions and variables below will exist.
#
namespace eval Logic {

  source [file join [file dirname [info script]] LogicBeginRRF.tcl]

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

    source [file join [file dirname [info script]] LogicPluginRRF.tcl]
    source [file join [file dirname [info script]] LogicAnalogicRRF.tcl]
    source [file join [file dirname [info script]] LogicNumericRRF.tcl]

    return 0
  }

  source [file join [file dirname [info script]] LogicEndRRF.tcl]

}

puts "Hello, world"
#
# This file has not been truncated
#