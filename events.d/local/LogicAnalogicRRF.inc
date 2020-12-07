  #global active_module

  # Example: Ignore all commands starting with 3 in the EchoLink module.
  #          Allow commands that have four or more digits.
  #if {$active_module == "EchoLink"} {
  #  if {[string length $cmd] < 4 && [string index $cmd 0] == "3"} {
  #    puts "Ignoring random connect command for module EchoLink: $cmd"
  #    return 1
  #  }
  #}

  # Handle the "force core command" mode where a command is forced to be
  # executed by the core command processor instead of by an active module.
  # The "force core command" mode is entered by prefixing a command by a star.
  #if {$active_module != "" && [string index $cmd 0] != "*"} {
  #  return 0
  #}
  #if {[string index $cmd 0] == "*"} {
  #  set cmd [string range $cmd 1 end]
  #}

  # Example: Custom command executed when DTMF 99 is received
  #if {$cmd == "99"} {
  #  puts "Executing external command"
  
  #  playMsg "Core" "online"
  #  exec ls &
  #  return 1
  #}
  
  proc sayIP {} {
    set result [exec /etc/spotnik/getIP]
    puts "$result"

    regexp "(\[0-9]{1,3})\.(\[0-9]{1,3})\.(\[0-9]{1,3})\.(\[0-9]{1,3})" $result all first second third fourth

    playSilence 100
    playNumber $first
    playSilence 100
    playMsg "default" "dash"
    playSilence 100
    playNumber $second
    playSilence 100
    playMsg "default" "dash"
    playSilence 100
    playNumber $third
    playSilence 100
    playMsg "default" "dash"
    playSilence 100
    playNumber $fourth

    playSilence 500;
  }

  # Internet test
  proc sayInternetStatus {} {
    if {[catch {exec ping -c 1 google.com} result] == 0} {
      puts "Internet Online Passed"
      playSilence 100
      playMsg "Core" "online"
    } else {
      puts "Internet Disconnected"
      #playMsg "MetarInfo" "not"
      #playMsg "Core" "online"
      #playSilence 500;
      playSilence 100
      playMsg "EchoLink" "link"
      playMsg "EchoLink" "disconnected"
    }
  }
  
  # Speak network IPs
  if {$cmd == "93"} {
    sayIP
    return 1
  }

  # Say if online or offline
  if {$cmd == "939"} {
    sayInternetStatus
    return 1
  }

  # 94 A documenter
  if {$cmd == "94"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec /usr/bin/nmcli con up SPOTNIK 
    exec /usr/bin route del default 
    return 1
  }

  # Mode Déconnecté du réseau, Autonome Relais seulement
  if {$cmd == "95"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.default &
    return 1
  }

  # 96 SvxReflector RRF
  if {$cmd == "96"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.rrf &
    return 1
  }

  # 97 SvxReflector FON
  if {$cmd == "97"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.fon &
    return 1
  }


  # 98 Salon Technique
  if {$cmd == "98"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.tec &
    return 1
  }

  # 99 Salon International
  if {$cmd == "99"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.int &
    return 1
  }

  # 100 Salon Bavardage
  if {$cmd == "100"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.bav &
    return 1
  }

  # 101 Salon Local
  if {$cmd == "101"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.loc &
    return 1
  }

  # 102 salon Sat
  if {$cmd == "102"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.exp &
    return 1
  }

  # 103 Echolink
  if {$cmd == "103"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.el &
    return 1
  }

  # 104 Regional à créer
  if {$cmd == "104"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.reg &
    return 1
  }

  # 105 Salon Expérimentation 
  if {$cmd == "105"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.fdv &
    return 1
  }

  # 106 Salon Numerique
  if {$cmd == "106"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.num &
    return 1
  }

  # 130 Salon Administrateurs
  if {$cmd == "130"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec nohup /etc/spotnik/restart.admin &
    return 1
  }
 
  # 1000 Reboot
  if {$cmd == "1000"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec reboot 
    return 1
  }

  # 1001 halt
  if {$cmd == "1001"} {
    puts "Executing external command"
    playMsg "Core" "online"
    exec halt 
    return 1
  }
