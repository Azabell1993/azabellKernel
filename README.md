Linux kernel
============

There are several guides for kernel developers and users. These guides can
be rendered in a number of formats, like HTML and PDF. Please read
Documentation/admin-guide/README.rst first.

In order to build the documentation, use ``make htmldocs`` or
``make pdfdocs``.  The formatted documentation can also be read online at:

    https://www.kernel.org/doc/html/latest/

There are various text files in the Documentation/ subdirectory,
several of them using the Restructured Text markup notation.

Please read the Documentation/process/changes.rst file, as it contains the
requirements for building and running the kernel, and information about
the problems which may result by upgrading your kernel.

////////////////////////////////////////////////////////////////
  
![image](https://github.com/Azabell1993/azabellKernel/assets/75885992/08e46506-05b4-4089-bef4-7d3a39446af1)  
  
### Ubuntu22.04 Custom Build Linux Kernel  
-- 
```
azabell@azabell-kernelhost:~/Desktop/linux-6.5.2/azabell$ sudo neofetch
            .-/+oossssoo+/-.               root@azabell-kernelhost 
        `:+ssssssssssssssssss+:`           ----------------------- 
      -+ssssssssssssssssssyyssss+-         OS: Ubuntu 22.04.3 LTS x86_64 
    .ossssssssssssssssssdMMMNysssso.       Host: VMware Virtual Platform None 
   /ssssssssssshdmmNNmmyNMMMMhssssss/      Kernel: 6.5.2azabellKernel 
  +ssssssssshmydMMMMMMMNddddyssssssss+     Uptime: 33 mins 
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Packages: 1948 (dpkg), 14 (snap) 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Shell: bash 5.1.16 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Resolution: 2776x1674 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   DE: GNOME 42.9 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   WM: Mutter 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   WM Theme: Adwaita 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Theme: Yaru [GTK2/3] 
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/    Icons: Yaru [GTK2/3] 
  +sssssssssdmydMMMMMMMMddddyssssssss+     Terminal: x-terminal-emul 
   /ssssssssssshdmNNNNmyNMMMMhssssss/      CPU: 11th Gen Intel i7-1195G7 (6) @ 2.918GHz 
    .ossssssssssssssssssdMMMNysssso.       GPU: 00:0f.0 VMware SVGA II Adapter 
      -+sssssssssssssssssyyyssss+-         Memory: 1111MiB / 3876MiB 
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.                                       
                                                                   
```  



### azabell/azabell.c

```
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(azabell) {
	printk("azabell kernel\n");
	return (0);
}
```  
  
https://github.com/Azabell1993/azabellKernel/blob/4f74b022d8fa3e54e5c4c3204964d4ace8a48569/azabell/azabell.c#L1-L7



  
```
obj-y := azabell.o
```  
  
https://github.com/Azabell1993/azabellKernel/blob/4f74b022d8fa3e54e5c4c3204964d4ace8a48569/azabell/Makefile#L1

  
  
### Makefile
https://github.com/Azabell1993/azabellKernel/blob/4f74b022d8fa3e54e5c4c3204964d4ace8a48569/Makefile#L5  
https://github.com/Azabell1993/azabellKernel/blob/4f74b022d8fa3e54e5c4c3204964d4ace8a48569/Makefile#L754-L759  

  
  
### include/linux/syscalls.h  
```
asmlinkage long sys_azabell(void);
```  
  
### arch/x86/entry/syscalls/syscall_64.tbl
https://github.com/Azabell1993/azabellKernel/blob/4f74b022d8fa3e54e5c4c3204964d4ace8a48569/arch/x86/entry/syscalls/syscall_64.tbl#L376   
  
  
  
#### 프로젝트 소개  
 이 프로젝트는 기존 리눅스 커널에 새로운 시스템 콜을 추가하는 것을 목표로 하였습니다. 제가 선택한 시스템 콜은 452번이며, 이를 통해 사용자 공간과 커널 간의 상호작용을 실험해보았습니다. 해당 시스템 콜은 링크에서 확인할 수 있습니다.  
  
### 452번 시스템 콜 기능  
이 시스템 콜은 새로운 기능을 제공합니다. 자세한 내용은 여기에서 확인할 수 있습니다. 간단히 말하자면, 이 콜을 통해 어떤 특정 작업을 수행하거나 정보를 얻을 수 있게 되었습니다.  
  
### 프로젝트 구조  
프로젝트는 크게 커널 소스 코드 및 사용자 공간에서 실행되는 테스트 프로그램으로 나뉘어집니다. 각 부분의 코드와 빌드 방법 등은 깃허브 저장소에서 확인 가능합니다.  

### 빌드 및 실행 방법  
프로젝트를 빌드하고 실행하는 방법은 이 문서에 상세히 기술되어 있습니다. 필요한 의존성 및 컴파일러 버전 등을 확인하고 따라하시면 됩니다.  

```
$ sudo make -j$(nproc)
$ sudo make modules_install install
$ sudo update-grub
$ sudo reboot
$ sudo uname -r
```  

