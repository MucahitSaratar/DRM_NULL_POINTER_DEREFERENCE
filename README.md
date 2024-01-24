# \*DAY DRM NULL POINTER DEREFERENCE POC

Tested on Oppo A55 up-to-date phone

## Dmesg Logs

```txt
[ 2266.911820]  (1)[19100:exploit][drm:drm_mode_legacy_fb_format] *ERROR* bad bpp, assuming x8r8g8b8 pixel format
[ 2266.911859]  (1)[19100:exploit]Unable to handle kernel access to user memory outside uaccess routines at virtual address 0000000000000008
[ 2266.911867]  (1)[19100:exploit]Mem abort info:
[ 2266.911874]  (1)[19100:exploit]  ESR = 0x96000005
[ 2266.911881]  (1)[19100:exploit]  Exception class = DABT (current EL), IL = 32 bits
[ 2266.911888]  (1)[19100:exploit]  SET = 0, FnV = 0
[ 2266.911895]  (1)[19100:exploit]  EA = 0, S1PTW = 0
[ 2266.911901]  (1)[19100:exploit]Data abort info:
[ 2266.911907]  (1)[19100:exploit]  ISV = 0, ISS = 0x00000005
[ 2266.911914]  (1)[19100:exploit]  CM = 0, WnR = 0
[ 2266.911926]  (1)[19100:exploit]user pgtable: 4k pages, 39-bit VAs, pgdp = 00000000c9e61b2a
[ 2266.911932]  (1)[19100:exploit][0000000000000008] pgd=0000000117a51003, pud=0000000117a51003, pmd=0000000000000000
[ 2266.911951] -(1)[19100:exploit]Internal error: Oops: 96000005 [#1] PREEMPT SMP
[ 2266.911971] -(1)[19100:exploit]panic after bootup @2024-1-6 22:39:37
[ 2266.925710]  (4)[2225:main_thread][wlan][2225]kalSetPerfReport:(SW4 INFO) Rate[144][0][0][0] RCPI[137][0][0][0]
[ 2266.925791]  (4)[2225:main_thread][wlan][2225]wlanLinkQualityMonitor:(SW4 INFO) Link Quality: Tx(rate:650, total:0, retry:31086973307733, fail:0, RTS fail:0, ACK fail:0), Rx(rate:10, total:0, dup:3, error:0), PER(0), Congestion(idle slot:0, diff:0, AwakeDur:0)
[ 2266.926691]  (6)[2225:main_thread][wlan][2225]nicRxProcessEventPacket:(RX INFO) Not static config event: id=0xFD, seq=47
[ 2266.926842] -(1)[19100:exploit][wlan][2225]nicRxProcessEventPacket:(RX INFO) Not static config event: id=0x21, seq=48
[ 2266.933412] -(1)[19100:exploit]Kernel Offset: 0x1ceb200000 from 0xffffff8008000000
[ 2266.933436] -(1)[19100:exploit]PHYS_OFFSET: 0xffffffc900000000
[ 2266.933443] -(1)[19100:exploit]Modules linked in: wlan_drv_gen4m ffffff9c8df93000 ffffff9c8e216000 2629632 249856 (O) wmt_chrdev_wifi ffffff9c8df85000 ffffff9c8df8e000 32768 16384 (O) gps_drv ffffff9c8df70000 ffffff9c8df80000 61440 16384 (O) fmradio_drv_mt6631 ffffff9c8df3c000 ffffff9c8df68000 176128 28672 (O) bt_drv_connac1x ffffff9c8df1a000 ffffff9c8df26000 45056 16384 (O) wmt_drv ffffff9c8de05000 ffffff9c8df1a000 1130496 139264 (O) connfem ffffff9c8ddf6000 ffffff9c8de00000 36864 16384 (O) fpsgo ffffff9c8dcd8000 ffffff9c8ddf2000 1150976 12288 (PO) trace_mmstat ffffff9c8dc6d000 ffffff9c8dc72000 16384 16384  mt6357_accdet ffffff9c8dc5e000 ffffff9c8dc68000 36864 16384 
[ 2266.944873] -(1)[19100:exploit]mrdump: add UFS:0xffffff9cf582d9b4 sz:0x0 failed
[ 2266.946272] -(1)[19100:exploit]mrdump: add CCCI:0xfffffff806560000 sz:0x0 failed
[ 2266.946296] -(1)[19100:exploit]CPU: 1 PID: 19100 Comm: exploit Tainted: P        W  O      4.19.191+ #1
[ 2266.946305] -(1)[19100:exploit]Hardware name: MT6765G (DT)
[ 2266.946315] -(1)[19100:exploit]pstate: 60400005 (nZCv daif +PAN -UAO)
[ 2266.946339] -(1)[19100:exploit]pc : drm_get_format_info+0x1c/0x44
[ 2266.946354] -(1)[19100:exploit]lr : drm_internal_framebuffer_create+0xb0/0x37c
[ 2266.946362] -(1)[19100:exploit]sp : ffffff800e79ba50
[ 2266.946368] -(1)[19100:exploit]x29: ffffff800e79ba50 x28: fffffff799845a00
[ 2266.946377] -(1)[19100:exploit]x27: 000000000000001c x26: ffffff9cf451c008 
[ 2266.946386] -(1)[19100:exploit]x25: fffffff83f051000 x24: 000000000000001c 
[ 2266.946395] -(1)[19100:exploit]x23: 0000000000000010 x22: 0000000030334258 
[ 2266.946403] -(1)[19100:exploit]x21: fffffff80400f000 x20: fffffff80400f000 
[ 2266.946412] -(1)[19100:exploit]x19: ffffff800e79bb10 x18: ffffff9cf544a6b8 
[ 2266.946421] -(1)[19100:exploit]x17: 0000000000000000 x16: 0000000000000000 
[ 2266.946429] -(1)[19100:exploit]x15: 0000000000000006 x14: 676e696d75737361 
[ 2266.946438] -(1)[19100:exploit]x13: 00000000000d600e x12: 0000000000000000 
[ 2266.946447] -(1)[19100:exploit]x11: 0000000000000000 x10: 0000000034325258 
[ 2266.946455] -(1)[19100:exploit]x9 : ffffff9cf451c64c x8 : 0000000000000000 
[ 2266.946463] -(1)[19100:exploit]x7 : 0000000000000000 x6 : ffffff9cf554cb36 
[ 2266.946472] -(1)[19100:exploit]x5 : 0000000000004a9c x4 : 0000000000000000 
[ 2266.946480] -(1)[19100:exploit]x3 : 0000000000000000 x2 : 0000000000000000 
[ 2266.946488] -(1)[19100:exploit]x1 : ffffff800e79bb10 x0 : fffffff80400f000 
[ 2266.946501] -(1)[19100:exploit]CPU: 1 PID: 19100 Comm: exploit Tainted: P        W  O      4.19.191+ #1
[ 2266.946508] -(1)[19100:exploit]Hardware name: MT6765G (DT)
[ 2266.946516] -(1)[19100:exploit]Call trace:
[ 2266.946531] -(1)[19100:exploit] dump_backtrace+0x0/0x198
[ 2266.946539] -(1)[19100:exploit] show_stack+0x20/0x2c
[ 2266.946551] -(1)[19100:exploit] dump_stack+0xb8/0xf0
[ 2266.946565] -(1)[19100:exploit] mrdump_common_die+0x198/0x23c
[ 2266.946573] -(1)[19100:exploit] ipanic_die+0x34/0x44
[ 2266.946586] -(1)[19100:exploit] atomic_notifier_call_chain+0x50/0x88
[ 2266.946595] -(1)[19100:exploit] notify_die+0x38/0x5c
[ 2266.946603] -(1)[19100:exploit] die+0xb0/0x380
[ 2266.946615] -(1)[19100:exploit] die_kernel_fault+0x64/0x74
[ 2266.946627] -(1)[19100:exploit] do_page_fault+0x2fc/0x4c0
[ 2266.946635] -(1)[19100:exploit] do_translation_fault+0x50/0x6c
[ 2266.946644] -(1)[19100:exploit] do_mem_abort+0x5c/0xfc
[ 2266.946654] -(1)[19100:exploit] el1_da+0x1c/0xac
[ 2266.946662] -(1)[19100:exploit] drm_get_format_info+0x1c/0x44
[ 2266.946671] -(1)[19100:exploit] drm_internal_framebuffer_create+0xb0/0x37c
[ 2266.946680] -(1)[19100:exploit] drm_mode_addfb2+0x48/0xc8
[ 2266.946689] -(1)[19100:exploit] drm_mode_addfb+0xac/0xe4
[ 2266.946697] -(1)[19100:exploit] drm_mode_addfb_ioctl+0x30/0x40
[ 2266.946707] -(1)[19100:exploit] drm_ioctl_kernel+0xc4/0x104
[ 2266.946716] -(1)[19100:exploit] drm_ioctl+0x228/0x3a8
[ 2266.946728] -(1)[19100:exploit] do_vfs_ioctl+0x670/0xec0
[ 2266.946736] -(1)[19100:exploit] ksys_ioctl+0x74/0x9c
[ 2266.946745] -(1)[19100:exploit] __arm64_sys_ioctl+0x24/0x34
[ 2266.946755] -(1)[19100:exploit] oplus_invoke_syscall+0x6c/0x15c
[ 2266.946766] -(1)[19100:exploit] el0_svc_common+0x9c/0x128
[ 2266.946775] -(1)[19100:exploit] el0_svc_handler+0x68/0x84
[ 2266.946783] -(1)[19100:exploit] el0_svc+0x8/0x300
```
