#!/bin/sh
# This script was generated using Makeself 2.3.0

ORIG_UMASK=`umask`
if test "n" = n; then
    umask 077
fi

CRCsum="1398154729"
MD5="0dbec617ba52198b21e9339b255018f6"
TMPROOT=${TMPDIR:=/tmp}
USER_PWD="$PWD"; export USER_PWD

label="Extracting potd-q38"
script="echo"
scriptargs="The initial files can be found in the newly created directory: potd-q38"
licensetxt=""
helpheader=''
targetdir="potd-q38"
filesizes="1974"
keep="y"
nooverwrite="n"
quiet="n"
nodiskspace="n"

print_cmd_arg=""
if type printf > /dev/null; then
    print_cmd="printf"
elif test -x /usr/ucb/echo; then
    print_cmd="/usr/ucb/echo"
else
    print_cmd="echo"
fi

unset CDPATH

MS_Printf()
{
    $print_cmd $print_cmd_arg "$1"
}

MS_PrintLicense()
{
  if test x"$licensetxt" != x; then
    echo "$licensetxt"
    while true
    do
      MS_Printf "Please type y to accept, n otherwise: "
      read yn
      if test x"$yn" = xn; then
        keep=n
	eval $finish; exit 1
        break;
      elif test x"$yn" = xy; then
        break;
      fi
    done
  fi
}

MS_diskspace()
{
	(
	if test -d /usr/xpg4/bin; then
		PATH=/usr/xpg4/bin:$PATH
	fi
	df -kP "$1" | tail -1 | awk '{ if ($4 ~ /%/) {print $3} else {print $4} }'
	)
}

MS_dd()
{
    blocks=`expr $3 / 1024`
    bytes=`expr $3 % 1024`
    dd if="$1" ibs=$2 skip=1 obs=1024 conv=sync 2> /dev/null | \
    { test $blocks -gt 0 && dd ibs=1024 obs=1024 count=$blocks ; \
      test $bytes  -gt 0 && dd ibs=1 obs=1024 count=$bytes ; } 2> /dev/null
}

MS_dd_Progress()
{
    if test x"$noprogress" = xy; then
        MS_dd $@
        return $?
    fi
    file="$1"
    offset=$2
    length=$3
    pos=0
    bsize=4194304
    while test $bsize -gt $length; do
        bsize=`expr $bsize / 4`
    done
    blocks=`expr $length / $bsize`
    bytes=`expr $length % $bsize`
    (
        dd ibs=$offset skip=1 2>/dev/null
        pos=`expr $pos \+ $bsize`
        MS_Printf "     0%% " 1>&2
        if test $blocks -gt 0; then
            while test $pos -le $length; do
                dd bs=$bsize count=1 2>/dev/null
                pcent=`expr $length / 100`
                pcent=`expr $pos / $pcent`
                if test $pcent -lt 100; then
                    MS_Printf "\b\b\b\b\b\b\b" 1>&2
                    if test $pcent -lt 10; then
                        MS_Printf "    $pcent%% " 1>&2
                    else
                        MS_Printf "   $pcent%% " 1>&2
                    fi
                fi
                pos=`expr $pos \+ $bsize`
            done
        fi
        if test $bytes -gt 0; then
            dd bs=$bytes count=1 2>/dev/null
        fi
        MS_Printf "\b\b\b\b\b\b\b" 1>&2
        MS_Printf " 100%%  " 1>&2
    ) < "$file"
}

MS_Help()
{
    cat << EOH >&2
${helpheader}Makeself version 2.3.0
 1) Getting help or info about $0 :
  $0 --help   Print this message
  $0 --info   Print embedded info : title, default target directory, embedded script ...
  $0 --lsm    Print embedded lsm entry (or no LSM)
  $0 --list   Print the list of files in the archive
  $0 --check  Checks integrity of the archive

 2) Running $0 :
  $0 [options] [--] [additional arguments to embedded script]
  with following options (in that order)
  --confirm             Ask before running embedded script
  --quiet		Do not print anything except error messages
  --noexec              Do not run embedded script
  --keep                Do not erase target directory after running
			the embedded script
  --noprogress          Do not show the progress during the decompression
  --nox11               Do not spawn an xterm
  --nochown             Do not give the extracted files to the current user
  --nodiskspace         Do not check for available disk space
  --target dir          Extract directly to a target directory
                        directory path can be either absolute or relative
  --tar arg1 [arg2 ...] Access the contents of the archive through the tar command
  --                    Following arguments will be passed to the embedded script
EOH
}

MS_Check()
{
    OLD_PATH="$PATH"
    PATH=${GUESS_MD5_PATH:-"$OLD_PATH:/bin:/usr/bin:/sbin:/usr/local/ssl/bin:/usr/local/bin:/opt/openssl/bin"}
	MD5_ARG=""
    MD5_PATH=`exec <&- 2>&-; which md5sum || command -v md5sum || type md5sum`
    test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which md5 || command -v md5 || type md5`
	test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which digest || command -v digest || type digest`
    PATH="$OLD_PATH"

    if test x"$quiet" = xn; then
		MS_Printf "Verifying archive integrity..."
    fi
    offset=`head -n 532 "$1" | wc -c | tr -d " "`
    verb=$2
    i=1
    for s in $filesizes
    do
		crc=`echo $CRCsum | cut -d" " -f$i`
		if test -x "$MD5_PATH"; then
			if test x"`basename $MD5_PATH`" = xdigest; then
				MD5_ARG="-a md5"
			fi
			md5=`echo $MD5 | cut -d" " -f$i`
			if test x"$md5" = x00000000000000000000000000000000; then
				test x"$verb" = xy && echo " $1 does not contain an embedded MD5 checksum." >&2
			else
				md5sum=`MS_dd_Progress "$1" $offset $s | eval "$MD5_PATH $MD5_ARG" | cut -b-32`;
				if test x"$md5sum" != x"$md5"; then
					echo "Error in MD5 checksums: $md5sum is different from $md5" >&2
					exit 2
				else
					test x"$verb" = xy && MS_Printf " MD5 checksums are OK." >&2
				fi
				crc="0000000000"; verb=n
			fi
		fi
		if test x"$crc" = x0000000000; then
			test x"$verb" = xy && echo " $1 does not contain a CRC checksum." >&2
		else
			sum1=`MS_dd_Progress "$1" $offset $s | CMD_ENV=xpg4 cksum | awk '{print $1}'`
			if test x"$sum1" = x"$crc"; then
				test x"$verb" = xy && MS_Printf " CRC checksums are OK." >&2
			else
				echo "Error in checksums: $sum1 is different from $crc" >&2
				exit 2;
			fi
		fi
		i=`expr $i + 1`
		offset=`expr $offset + $s`
    done
    if test x"$quiet" = xn; then
		echo " All good."
    fi
}

UnTAR()
{
    if test x"$quiet" = xn; then
		tar $1vf - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    else

		tar $1f - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    fi
}

finish=true
xterm_loop=
noprogress=n
nox11=n
copy=none
ownership=y
verbose=n

initargs="$@"

while true
do
    case "$1" in
    -h | --help)
	MS_Help
	exit 0
	;;
    -q | --quiet)
	quiet=y
	noprogress=y
	shift
	;;
    --info)
	echo Identification: "$label"
	echo Target directory: "$targetdir"
	echo Uncompressed size: 20 KB
	echo Compression: gzip
	echo Date of packaging: Tue Mar  5 18:49:57 CST 2019
	echo Built with Makeself version 2.3.0 on linux-gnu
	echo Build command was: "./makeself/makeself.sh \\
    \"--notemp\" \\
    \"../../questions/potd3_038_BTree_Removal/potd-q38\" \\
    \"../../questions/potd3_038_BTree_Removal/clientFilesQuestion/potd-q38.sh\" \\
    \"Extracting potd-q38\" \\
    \"echo\" \\
    \"The initial files can be found in the newly created directory: potd-q38\""
	if test x"$script" != x; then
	    echo Script run after extraction:
	    echo "    " $script $scriptargs
	fi
	if test x"" = xcopy; then
		echo "Archive will copy itself to a temporary location"
	fi
	if test x"n" = xy; then
		echo "Root permissions required for extraction"
	fi
	if test x"y" = xy; then
	    echo "directory $targetdir is permanent"
	else
	    echo "$targetdir will be removed after extraction"
	fi
	exit 0
	;;
    --dumpconf)
	echo LABEL=\"$label\"
	echo SCRIPT=\"$script\"
	echo SCRIPTARGS=\"$scriptargs\"
	echo archdirname=\"potd-q38\"
	echo KEEP=y
	echo NOOVERWRITE=n
	echo COMPRESS=gzip
	echo filesizes=\"$filesizes\"
	echo CRCsum=\"$CRCsum\"
	echo MD5sum=\"$MD5\"
	echo OLDUSIZE=20
	echo OLDSKIP=533
	exit 0
	;;
    --lsm)
cat << EOLSM
No LSM.
EOLSM
	exit 0
	;;
    --list)
	echo Target directory: $targetdir
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | UnTAR t
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
	--tar)
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	arg1="$2"
    if ! shift 2; then MS_Help; exit 1; fi
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | tar "$arg1" - "$@"
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
    --check)
	MS_Check "$0" y
	exit 0
	;;
    --confirm)
	verbose=y
	shift
	;;
	--noexec)
	script=""
	shift
	;;
    --keep)
	keep=y
	shift
	;;
    --target)
	keep=y
	targetdir=${2:-.}
    if ! shift 2; then MS_Help; exit 1; fi
	;;
    --noprogress)
	noprogress=y
	shift
	;;
    --nox11)
	nox11=y
	shift
	;;
    --nochown)
	ownership=n
	shift
	;;
    --nodiskspace)
	nodiskspace=y
	shift
	;;
    --xwin)
	if test "n" = n; then
		finish="echo Press Return to close this window...; read junk"
	fi
	xterm_loop=1
	shift
	;;
    --phase2)
	copy=phase2
	shift
	;;
    --)
	shift
	break ;;
    -*)
	echo Unrecognized flag : "$1" >&2
	MS_Help
	exit 1
	;;
    *)
	break ;;
    esac
done

if test x"$quiet" = xy -a x"$verbose" = xy; then
	echo Cannot be verbose and quiet at the same time. >&2
	exit 1
fi

if test x"n" = xy -a `id -u` -ne 0; then
	echo "Administrative privileges required for this archive (use su or sudo)" >&2
	exit 1	
fi

if test x"$copy" \!= xphase2; then
    MS_PrintLicense
fi

case "$copy" in
copy)
    tmpdir=$TMPROOT/makeself.$RANDOM.`date +"%y%m%d%H%M%S"`.$$
    mkdir "$tmpdir" || {
	echo "Could not create temporary directory $tmpdir" >&2
	exit 1
    }
    SCRIPT_COPY="$tmpdir/makeself"
    echo "Copying to a temporary location..." >&2
    cp "$0" "$SCRIPT_COPY"
    chmod +x "$SCRIPT_COPY"
    cd "$TMPROOT"
    exec "$SCRIPT_COPY" --phase2 -- $initargs
    ;;
phase2)
    finish="$finish ; rm -rf `dirname $0`"
    ;;
esac

if test x"$nox11" = xn; then
    if tty -s; then                 # Do we have a terminal?
	:
    else
        if test x"$DISPLAY" != x -a x"$xterm_loop" = x; then  # No, but do we have X?
            if xset q > /dev/null 2>&1; then # Check for valid DISPLAY variable
                GUESS_XTERMS="xterm gnome-terminal rxvt dtterm eterm Eterm xfce4-terminal lxterminal kvt konsole aterm terminology"
                for a in $GUESS_XTERMS; do
                    if type $a >/dev/null 2>&1; then
                        XTERM=$a
                        break
                    fi
                done
                chmod a+x $0 || echo Please add execution rights on $0
                if test `echo "$0" | cut -c1` = "/"; then # Spawn a terminal!
                    exec $XTERM -title "$label" -e "$0" --xwin "$initargs"
                else
                    exec $XTERM -title "$label" -e "./$0" --xwin "$initargs"
                fi
            fi
        fi
    fi
fi

if test x"$targetdir" = x.; then
    tmpdir="."
else
    if test x"$keep" = xy; then
	if test x"$nooverwrite" = xy && test -d "$targetdir"; then
            echo "Target directory $targetdir already exists, aborting." >&2
            exit 1
	fi
	if test x"$quiet" = xn; then
	    echo "Creating directory $targetdir" >&2
	fi
	tmpdir="$targetdir"
	dashp="-p"
    else
	tmpdir="$TMPROOT/selfgz$$$RANDOM"
	dashp=""
    fi
    mkdir $dashp $tmpdir || {
	echo 'Cannot create target directory' $tmpdir >&2
	echo 'You should try option --target dir' >&2
	eval $finish
	exit 1
    }
fi

location="`pwd`"
if test x"$SETUP_NOCHECK" != x1; then
    MS_Check "$0"
fi
offset=`head -n 532 "$0" | wc -c | tr -d " "`

if test x"$verbose" = xy; then
	MS_Printf "About to extract 20 KB in $tmpdir ... Proceed ? [Y/n] "
	read yn
	if test x"$yn" = xn; then
		eval $finish; exit 1
	fi
fi

if test x"$quiet" = xn; then
	MS_Printf "Uncompressing $label"
fi
res=3
if test x"$keep" = xn; then
    trap 'echo Signal caught, cleaning up >&2; cd $TMPROOT; /bin/rm -rf $tmpdir; eval $finish; exit 15' 1 2 3 15
fi

if test x"$nodiskspace" = xn; then
    leftspace=`MS_diskspace $tmpdir`
    if test -n "$leftspace"; then
        if test "$leftspace" -lt 20; then
            echo
            echo "Not enough space left in "`dirname $tmpdir`" ($leftspace KB) to decompress $0 (20 KB)" >&2
            echo "Use --nodiskspace option to skip this check and proceed anyway" >&2
            if test x"$keep" = xn; then
                echo "Consider setting TMPDIR to a directory with more free space."
            fi
            eval $finish; exit 1
        fi
    fi
fi

for s in $filesizes
do
    if MS_dd_Progress "$0" $offset $s | eval "gzip -cd" | ( cd "$tmpdir"; umask $ORIG_UMASK ; UnTAR xp ) 1>/dev/null; then
		if test x"$ownership" = xy; then
			(PATH=/usr/xpg4/bin:$PATH; cd "$tmpdir"; chown -R `id -u` .;  chgrp -R `id -g` .)
		fi
    else
		echo >&2
		echo "Unable to decompress $0" >&2
		eval $finish; exit 1
    fi
    offset=`expr $offset + $s`
done
if test x"$quiet" = xn; then
	echo
fi

cd "$tmpdir"
res=0
if test x"$script" != x; then
    if test x"$verbose" = x"y"; then
		MS_Printf "OK to execute: $script $scriptargs $* ? [Y/n] "
		read yn
		if test x"$yn" = x -o x"$yn" = xy -o x"$yn" = xY; then
			eval "\"$script\" $scriptargs \"\$@\""; res=$?;
		fi
    else
		eval "\"$script\" $scriptargs \"\$@\""; res=$?
    fi
    if test "$res" -ne 0; then
		test x"$verbose" = xy && echo "The program '$script' returned an error code ($res)" >&2
    fi
fi
if test x"$keep" = xn; then
    cd $TMPROOT
    /bin/rm -rf $tmpdir
fi
eval $finish; exit $res
‹     íYmo7ö×òWŒÕ ÝµõnÉ$Û×´v9¸pÍáR$©±^QÒÂ«¥Arûÿ÷ÎûÂ•6v®¨S?hWäÌðáp8œ™mw¶ž¼u±‡ôì»î3o[½½Aÿ ×¶º½îð`†[_¡¥J`k§ÓéíçéÿF[»óÓÉù¹˜ðöü	÷0øÜþ÷÷ú{´ÿ{û½AûÑ¸ÿÝÍþ?yûþZ³E "	9cßGI§‡JË(™;=Kj!Ã¡4ÔPØÜ1Àv)D‘ºˆy0½€#@*>6#JOF#Ë~%úxÌ<Ñêb}¼ºsá<Š'’'Y1äùpw¿Òµ6ÇÒÏpèy¤ZÇÅ¤ˆmi%Z!K¸/£¤æ&.§±øh1@BË4D“¸¼)t Q= £Ù\çÌÞ¥R|¤þÀrL¥X@Ì§Ttã€ßÎ‰¼d°0ßÔL¨\"tÃ'¨SšºPÆ;äùPÊ‘\§2WSÜ"	„AB&"á9m§Ü&CÆÿMè½4QÑ,¡y&7M(þ	‰ˆü1»3f4´?Ïyx‘i-yIº¸äÄ´ØSˆ\¾Ù«„biªÍÊ…#ã)rÀy­ Ú1Ãí²DF[öMX f*K—éâZÁŒ´3y^±B^ä‘#eX:Ì¨£¤*µ‘¬ÑH¡ ®y1j%O…Ébi, Éd­À¢„J¥n†€ßDÊ.—ŽŒ»ÒHã0-4aÍÁç—iœh³W£s='‹‰¢D-Ñ™£9Ykr™S›[£!.Ï7u¯K| ÛŠMÒP@¾T†\©i;Ú·¬/QKg8¯‡§×( Y"ØÉçlFŽ·f¶6íÿ¹ÿ	®ø4ŠùÓÆÜÿÝaw°ÿõû{ÃÍýÿ5ÚéÛÓó¿œâ¸À“Í^ÿô¯_³÷¶(`[0öóÛ·8ÆA2ÛÝ¥/Ï^ü“ˆ[x÷…»»Ýh…ÐšAëuZÿâù–;;qXÏNÖ9Cò<ó2<>cå;õ0Ÿ}÷Ì;;ñáÙï@/FŒ-Ï~dÌbYìáõ5#J¤>ófÉsV5r–øKˆî&±ïZr­)ì n¨ßöùÏõõ·Œÿ÷‹ø€¿9ÿýÍùÿ*ñßG{,ŽÌ‚x&d¤ç‹ÚÔ èj8YeƒRŒÎ­0
"–\jÏ¹Ý¥Ú†ë.¡BÑøÔ Pƒ9ˆŽŽÎÿsvæC`(£°ËSÑÿøÆÈÒããÐÈt‚þ6Qx>Žíîú6ë€Ý#;ŸvJo…é]ôÁ‡ÝD9é=c¥ÐÉ¡\„±"‰Ø•ö	]øT3Ô)ÞÞÛÑOÐCJèÓÏýó^ös	V“L-»p7èÞkÇzp×ë6QheÞk(úp7ÄÑ}+¡úHÞ²ë7!ö–=|HoÙ÷p¤]¤#íëTÍ/.ƒðÊ{?2.Ëq'QœR\>f9þP¤¡ñ^4è-·˜çÖN°Çòd?b wÿ‹Ì°2a>M•ÑØ€…c¬à~geËs-¾¸\¥±Fl+±.iÞ¬ª	½&ýñš^©J]Ðÿ°ºññØõWÛAã\l7ÖUU¼V÷ß’æÍ²ãÙ¥ã¹‰ëÿLýï©‚€Gîÿao5þßëõ6÷ÿW½ÿ«7¶sá+…G³=4(ã‡M½È©Gd¯Ó7¯O^à7‘Jtx¸P”Ë·Í`†#»ïþ©r$°/¯EþuÈ/­AæÊ+ìl4úâ2d®D·R+)-Lrƒ°²Æ¢LúÊ!IèºUÑâ:¾­h±†Aª¸[¥5 }})•¢RRÜ!Þ|þÚ6®"Fõ&À¤¶æVØx"ÒÙ¼´ñ`ªÉ‚IÔv{M½ÍäÌ$_RÎíî´ ÷a\@w¬˜¨×ƒe¢of;PÞÜÎ¢
ÝFú£×wÓHS-8ðªÆ-Í-Öj¸íŠúu}WÜñNñ^Uum-ÿDXk4ÛXØ$N®4ŒÊI•"meCr9ˆš ué²ÌzÅoãÊŸ§7Âç£¼Êû©$Ã1gÓ1ª@
T>x4<a(=ƒi¶«øžñ£+¿s("§½<‚xHq´š‰eõýfÎýÙ<ä±Lä3¹8‰ˆ»hk™¹~›FGšœ¹š‹=H,ÄÄÑ_ŸÛÊ^í/à¼‡:8ÅZLn´‚¦ÃªÎvRkä˜ëxí§*ô»OP.ý¿
’HßZ L§½[½m+­uœ'EþØ.Jó‡®×þxõüwr´Îð.—öamŽµùW“Åçæ´PZnÉøŒGä£ªMø®q‚i”L<#§}Ég”@7­Ø6Fòô‡t]U qo¹T~æ^«IKññÅä.æ#Šéo·Ûõ|ÁìÉ…jží¯šGxþÍ…ozuÉ(¹2FDš6l‰Þ Õc9ÜfnÕ˜S´ròJ¤®_@¯¦Òø—ò{Mé¦ë<·c­ ÎWWQÙôp5«¸ÔÜbÜ»¹4îüKéq«PÚY#¿zÎ6Y×¦mÚ¦mÚßßþ ÆðÛÌ (  