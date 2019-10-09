#ifndef _MODULE_CONFIG_H_
#define _MODULE_CONFIG_H_

#define TRA_LAYER (4)
#define NET_LAYER (3)
#define MAC_LAYER (2)
#define PHY_LAYER (1)


#define TRA_PID (1)             // 1 for udp
#define NET_PID (2)             // 1:Vbf 2:Srt 3:Dab 4:Drt 5:DrtPlus for test 6:DrtPlusPlus 7:Dbpcr 8:RangeTest 9:Dbr
#define MAC_PID (6)             // 2 for aloha, 3 for fama, 4 for simple_aloha, 5 for new_aloha and for test, 6 for AlohaSpecial
#define PHY_PID (1)             // 4 for fsk 2 for aquasent 1 for simulate 64 for simulateWOSS 8 for qpsk 16 for fsk 32 for fsknewclient


#endif
