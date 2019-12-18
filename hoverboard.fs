
0     variable speed
0     variable steer
$aaaa constant header

: checksum ( -- checksum ) header speed @ steer @ xor xor ;
: send-lsb ( n -- sends 2 low bytes ) dup uart-emit 8 rshift uart-emit ;

: send checksum speed @ steer @ $aaaa send-lsb send-lsb send-lsb send-lsb ;

: halt ( -- ) 0 speed ! 0 steer ! send ;
: fwd ( speed --  ) speed ! send ;
: turn ( steer --  ) steer ! send ;

19200 uart-init





