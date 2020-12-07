  #modif TK4LS

  proc dvswitchQSY {cmd ambemode mode tune nom} {

    set dvs "/opt/Analog_Bridge/dvswitch.sh";

    puts "Executing external command"
    exec $dvs ambemode $ambemode
    exec $dvs mode $mode
    exec $dvs tune $tune
    playSilence 150
    playMsg "NUM" $nom;
    if {$mode != "YSF" && $mode != "P25" && $mode != "NXDN"} {
      playSilence 150;
      if {[string length $cmd] == "3"} {
        playNumber $cmd;
      } elseif { [string length $cmd] == "4" } {
        playNumber [string range $cmd 0 1];
        playSilence 50;
        playNumber [string range $cmd 2 3];
      } elseif {[string length $cmd] == "5"} {
        playNumber [string range $cmd 0 2];
        playSilence 50;
        playNumber [string range $cmd 3 4];
      }
    }
  }

  # dvswitchQSY $cmd "AMBEMODE" "MODE" "ROOM or TG" "SOUND"

  #
  # Mode numerique room YSF
  #

  # YSF-FRANCE
  if {$cmd == "3000"} {
    dvswitchQSY $cmd "YSFN" "YSF" "m55.evxonline.net:4200" "france"
    return 1
  }

  # YSF-IDF
  if {$cmd == "3001"} {
    dvswitchQSY $cmd "YSFN" "YSF" "ysf-fon.f1tzo.com:42001" "idf"
    return 1
  }

  # YSF-Alsace ?
  if {$cmd == "3002"} {
    dvswitchQSY $cmd "YSFN" "YSF" "xlx208.f5kav.org:42000" "ysf_alsace"
    return 1
  }

  # YSF-ZIT
  if {$cmd == "3003"} {
    dvswitchQSY $cmd "YSFN" "YSF" "151.80.143.185:42002" "room_zit"
    return 1
  }

  # YSF-Centre France
  if {$cmd == "3004"} {
    dvswitchQSY $cmd "YSFW" "YSF" "ysf-fon.f1tzo.com:42002" "centrefrance"
    return 1
  }

  # YSF-Alpes
  if {$cmd == "3005"} {
    dvswitchQSY $cmd "YSFN" "YSF" "217.182.66.229:42000" "ysf_alpes"
    return 1
  }

  # YSF-WALONNIE
  if {$cmd == "3006"} {
    dvswitchQSY $cmd "YSFN" "YSF" "vs49.evxonline.net:42000" "ysf_wallonie"
    return 1
  }

  # YSF-Haut-de-France
  if {$cmd == "3007"} {
    dvswitchQSY $cmd "YSFN" "YSF" "51.15.172.24:42001" "ysf_hdf"
    return 1
  }

  # YSF-Linux
  if {$cmd == "3008"} {
    dvswitchQSY $cmd "YSFN" "YSF" "213.32.19.95:42000" "ysf_linux"
    return 1
  }

  # YSF-Test
  if {$cmd == "3009"} {
    dvswitchQSY $cmd "YSFN" "YSF" "vps731279.ovh.net:42000" "ysf_test"
    return 1
  }

  # YSF-FraWide
  if {$cmd == "3010"} {
    dvswitchQSY $cmd "YSFW" "YSF" "ns3294400.ovh.net:42010" "frawide"
    return 1
  }

  # YSF-Emcom
  if {$cmd == "3012"} {
    dvswitchQSY $cmd "YSFN" "YSF" "78.206.208.208:42021" "Sc4fm"    
    playSilence 100;
    playNumber 30;
    playSilence 100;
    playNumber 12;
    return 1
  }

  # YSF-NordOuest
  if {$cmd == "3029"} {
    dvswitchQSY $cmd "YSFN" "YSF" "78.206.208.208:42000" "Sc4fm"
    playSilence 100;
    playNumber 30;
    playSilence 100;
    playNumber 29;
    return 1
  }

  # YSF-CANADA-FR
  if {$cmd == "3030"} {
    dvswitchQSY $cmd "YSFN" "YSF" "38.110.97.161:42000" "ysf_canada"
    return 1
  }

  # YSF-Cq CANADA
  if {$cmd == "3031"} {
    dvswitchQSY $cmd "YSFN" "YSF" "142.93.158.165:42002" "Sc4fm"
    playSilence 100;
    playNumber 30;
    playSilence 100;
    playNumber 31;
    return 1
  }

  # YSF DMRQ Canada
  if {$cmd == "3032"} {
    dvswitchQSY $cmd "YSFN" "YSF" "142.93.158.165:42002" "Sc4fm"
    playSilence 100;
    playNumber 30;
    playSilence 100;
    playNumber 32;
    return 1
  }

  # YSF-NANTES
  if {$cmd == "3044"} {
    dvswitchQSY $cmd "YSFN" "YSF" "f5ore.dyndns.org:42000" "ysf_nantes"
    return 1
  }

  # YSF-HB9VD
  if {$cmd == "3066"} {
    dvswitchQSY $cmd "YSFN" "YSF" "reflector.hb9vd.ch:42000" "ysf_hb9vd"
    return 1
  }

  # YSF-WireX
  if {$cmd == "3090"} {
    dvswitchQSY $cmd "YSFN" "YSF" "151.80.143.185:42001" "ysf_wirex"
    return 1
  }

  # YSF-FON
  if {$cmd == "3097"} {
    dvswitchQSY $cmd "YSFW" "YSF" "ysf-fon.f1tzo.com:42000" "Sfon"
    return 1
  }

  # YSF-INTERNATIONAL-RRF
  if {$cmd == "3099"} {
     dvswitchQSY $cmd "YSFW" "YSF" "ysf-fon.f1tzo.com:42005" "inter_rrf" 
     return 1
  }

  #
  # Mode numerique P25
  #

  # 40721 Canada Fr
  if {$cmd == "40721"} {
    dvswitchQSY $cmd "P25" "P25" "40721" "p25_canada"
    return 1
  }

  # 10208 France
  if {$cmd == "10208"} {
      dvswitchQSY $cmd "P25" "P25" "10208" "p25_france"
      return 1
  }

  #
  # Mode Numerique NXDN
  #

  # 65208 France
  if {$cmd == "65208"} {
    dvswitchQSY $cmd "NXDN" "NXDN" "65208" "nxdn_france"
    return 1
  }

  # 
  # Mode Numerique DMR
  #

  # DMR-208
  if {$cmd == "208"} {
    dvswitchQSY $cmd "DMR" "DMR" "208" "Tg-dmr"
    return 1
  }

  # DRM-2081
  if {$cmd == "2081"} {
    dvswitchQSY $cmd "DMR" "DMR" "2081" "Tg-dmr"
    return 1
  }

  # DMR-2082
  if {$cmd == "2082"} {
    dvswitchQSY $cmd "DMR" "DMR" "2082" "Tg-dmr"
    return 1
  }

  # DRM-2083
  if {$cmd == "2083"} {
    dvswitchQSY $cmd "DMR" "DMR" "2083" "Tg-dmr"
    return 1
  }

  # DMR-2084
  if {$cmd == "2084"} {
    dvswitchQSY $cmd "DMR" "DMR" "2084" "Tg-dmr"
    return 1
  }

  # DRM-2085
  if {$cmd == "2085"} {
    dvswitchQSY $cmd "DMR" "DMR" "2085" "Tg-dmr"
    return 1
  }

  # DMR-2089
  if {$cmd == "2089"} {
    dvswitchQSY $cmd "DMR" "DMR" "2089" "Tg-dmr"
    return 1
  }

  # DMR-20825
  if {$cmd == "20825"} {
    dvswitchQSY $cmd "DMR" "DMR" "20825" "Tg-dmr"
    return 1
  }

  # DMR-20854
  if {$cmd == "20854"} {
    dvswitchQSY $cmd "DMR" "DMR" "20854" "Tg-dmr"
    return 1
  }

  # DMR-20844
  if {$cmd == "20844"} {
    dvswitchQSY $cmd "DMR" "DMR" "20844" "Tg-dmr"
    return 1
  }

  # DMR-20867
  if {$cmd == "20867"} {
    dvswitchQSY $cmd "DMR" "DMR" "20867" "Tg-dmr"
    return 1
  }

  # DMR-20860
  if {$cmd == "20860"} {
    dvswitchQSY $cmd "DMR" "DMR" "20860" "Tg-dmr"
    return 1
  }

  # DMR-20879
  if {$cmd == "20879"} {
    dvswitchQSY $cmd "DMR" "DMR" "20879" "Tg-dmr"
    return 1
  }

  # DMR-2080
  if {$cmd == "2080"} {
    dvswitchQSY $cmd "DMR" "DMR" "2080" "Tg-dmr"
    return 1
  }

  # DMR-20800
  if {$cmd == "20800"} {
    dvswitchQSY $cmd "DMR" "DMR" "20800" "Tg-dmr"
    return 1
  }

  #
  # Mode Numerique D-Star pour essai il faut une clef Ambe
  #

  # 933C
  if {$cmd == "933"} {
    dvswitchQSY $cmd "DSTAR" "DSTAR" "DCS033CL" "Dstar"
    playSilence 50;
    spellWord cl;
    return 1
  }

