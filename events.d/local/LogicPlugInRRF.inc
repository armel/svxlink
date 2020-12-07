  # 999 Interrupteur DTMF  
  if { [file exists /tmp/DTMF] } {
    if {$cmd != "999" || $cmd != "202"} {
      return 1
    }
  }

  # 999 Interrupteur DTMF  
  if {$cmd == "999"} {
    if { [file exists /tmp/DTMF] } {
      file delete -force /tmp/DTMF
      playSilence 1500
      playFile /usr/share/svxlink/sounds/fr_FR/RRF/dtmfOn.wav      
    } else {
      set outfile [open "/tmp/DTMF" w]
      puts $outfile "DTMF OFF"
      close $outfile
      playSilence 1500
      playFile /usr/share/svxlink/sounds/fr_FR/RRF/dtmfOff.wav
    }
    return 1
  }

  # 200 Raptor start and stop
  if {$cmd == "200"} {
    puts "Executing external command"
    exec nohup /opt/RRFRaptor/RRFRaptor.sh & 
    return 1
  }

  # 201 Raptor quick scan
  if {$cmd == "201"} {
    puts "Executing external command"
    exec /opt/RRFRaptor/RRFRaptor.sh scan
    return 1
  }

  # 202 Raptor sound
  if {$cmd == "202"} {
    if { [file exists /tmp/RRFRaptor_status.tcl] } {
      source "/tmp/RRFRaptor_status.tcl"
      if {$RRFRaptor == "ON"} {
        playSilence 1500
        playFile /opt/RRFRaptor/sounds/active.wav     
      } else {
        playSilence 1500
        playFile /opt/RRFRaptor/sounds/desactive.wav
      }
    }
    return 1
  }

  # 203 Raptor quick scan sound
  if {$cmd == "203"} {
    if { [file exists /tmp/RRFRaptor_scan.tcl] } {
      source "/tmp/RRFRaptor_scan.tcl"
      if {$RRFRaptor == "None"} {
        playSilence 1500
        playFile /opt/RRFRaptor/sounds/qso_ko.wav        
      } else {
        playSilence 1500
        playFile /opt/RRFRaptor/sounds/qso_ok.wav
        if {$RRFRaptor == "RRF"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Srrf.wav      
        } elseif {$RRFRaptor == "FON"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Sfon.wav    
        } elseif {$RRFRaptor == "TECHNIQUE"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Stec.wav    
        } elseif {$RRFRaptor == "INTERNATIONAL"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Sint.wav    
        } elseif {$RRFRaptor == "LOCAL"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Sloc.wav    
        } elseif {$RRFRaptor == "BAVARDAGE"} {
          playFile /usr/share/svxlink/sounds/fr_FR/RRF/Sbav.wav    
        }        
      }
    }
    return 1
  }

  # 204 Interrupteur Timersalon
  if {$cmd == "204"} {
    if { [file exists /tmp/TIMER] } {
      file delete -force /tmp/TIMER
      exec nohup /etc/spotnik/timersalon.sh &
      playSilence 1500
      playFile /usr/share/svxlink/sounds/fr_FR/RRF/timersalonOn.wav
    } else {
      set outfile [open "/tmp/TIMER" w]
      puts $outfile "TIMER OFF"
      close $outfile
      exec /usr/bin/pkill -f timersalon
      playSilence 1500
      playFile /usr/share/svxlink/sounds/fr_FR/RRF/timersalonOff.wav
    }
    return 1
  }

