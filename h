
0 variable speed
0 variable steer

: checksum $aaaa speed @ steer @ xor xor ;
: send-lsb dup uart-emit 8 rshift uart-emit ;

\ : send $aaaa send-lsb steer @ send-lsb speed @ send-lsb checksum send-lsb ;
: send checksum speed @ steer @ $aaaa send-lsb send-lsb send-lsb send-lsb ;

: halt 0 speed ! 0 steer ! send ;
: fwd $0100 speed ! 0 steer ! send ;

19200 uart-init

: t 256 0 do i speed ! send 10 ms loop 1000 ms 1 256 do i speed ! send 10 ms -1 +loop ;

\ it's missing commands, seemingly randomly
\ need to have a look at the scope?  bloody pita



