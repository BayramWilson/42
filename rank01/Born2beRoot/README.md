*This project has been created as part of the 42 curriculum by bwilson.*

  

# Born2beRoot

  

## Description

  

This project focuses on learning and understanding the fundamental concepts of virtualization and system administration.

The goal is to configure a virtual machine as a real system administrator would do, rather than just running an OS with default settings.

  

My goal is to learn and understand the concepts of virtualization and to configure it like a real sysadmin is doing it.

I want to understand a computer before I write a lot of code on hardware level for my future C path.

  

---

  

## Instructions

  

### Start the virtual machine

1. Start the VM using VirtualBox or UTM.

2. Connect via SSH:

```

ssh -p <port> user@localhost

```

3. Log in with your credentials.

  

### Useful commands

- Switch to root:

```

su -

```

- Exit root or SSH session:

```

exit

```

  

---

  

## Filesystem & Partitioning

  

### Disk layout

  

- **sda**

- Main virtual disk

  <br>

- **sda1 (/boot)**

- Unencrypted boot partition

- Contains GRUB (bootloader), kernel (core of OS) and initramfs (initial RAM filesystem)

  <br>

- **sda5**

- Encrypted partition (LUKS)

- Contains LVM

  
---
### LVM structure

  

- **LVMGroup**

- Flexible volume management

- Allows resizing of logical volumes

  <br>

- **root**

- Contains the OS

  <br>

- **swap**

- Virtual memory when RAM is full

  <br>

- **home**

- Separates user data from system files

  
<br>

- **var/log**

- Prevents logs from filling `/` and crashing the system

  <br>

- **tmp**

- Temporary files created by applications

  
<br>

- **srv**

- Service data (web or application data)

  
<br>
I use an unencrypted `/boot`, then a LUKS-encrypted partition containing LVM.

Inside LVM, I split system, logs, user data, and temporary files into separate logical volumes

to improve security, stability, and maintainability.

---
### LVM Concepts

- **PV (Physical Volume)**  
  The foundational layer of LVM. A physical volume is a physical hard disk, SSD, or a partition on one of these devices that has been initialized for use with LVM.  
  LVM writes a metadata header to the device so it can be managed as part of LVM.

<br>

- **VG (Volume Group)**  
  A volume group is a storage pool created by combining one or more physical volumes.  
  The VG abstracts the underlying hardware and presents a single, unified pool of storage space.

<br>

- **LV (Logical Volume)**  
  Logical volumes are the usable storage units created from the space available in a volume group.  
  They behave like traditional disk partitions: you can format them with a filesystem (e.g. ext4 or XFS) and mount them to directories for use by the operating system and applications.


---

  

## Command List

  

- `lsblk` – show disk and partition layout

- `cryptsetup status sda5_crypt` – check encrypted volume status

- `lvdisplay` – show logical volumes

- `vgdisplay` – show volume groups

  

---

  

## Project Description

  

### Operating System Choice

  

I chose **Debian** for this project.

  

- **Debian**

- Community-driven

- Large ecosystem (APT)

- Very stable and well documented

- Good for general-purpose servers

  <br>

- **Rocky Linux**

- Enterprise-focused

- Red Hat compatible

- Long-term stability

  

### AppArmor vs SELinux

  

- Both are Mandatory Access Control systems

- AppArmor uses simpler path-based rules

- SELinux uses label-based policies and is more complex

  

For strict fine-grained policies SELinux is stronger, but for simplicity and beginners AppArmor is more suitable.

  

### UFW vs firewalld

  

- **UFW**

- Very user-friendly

- Easy to configure

- Static rules

- Good for beginners

  <br>

- **firewalld**

- Dynamic, zone-based

- More complex

- Better for multi-interface environments

  

I chose UFW for simplicity.

  

### VirtualBox vs UTM

  

- **UTM**

- Better for Apple Silicon Macs

- Uses native virtualization

- Lightweight and efficient

  <br>

- **VirtualBox**

- Broad x86/x64 support

- Advanced features (snapshots, compatibility)

- Better for Intel Macs

  

## apt vs. aptitude

  

- **apt**

- Newer and more user-focused

- Provides simple commands (apt install, apt update, etc.)

- Clean, readable, and colored interface

<br>

- **aptitude**

- Older and feature-rich

- Text-based interactive interface

- Smarter dependency handling (automatically removes unused packages)

  

I chose apt because it offers simpler commands and I am already familiar with it.

  
  

---

  

### Additional Services (Bonus)

  

#### Docker & n8n

  

I installed Docker and set up an **n8n** container.

  

- n8n runs at:

```

http://127.0.0.1:5678/

```

  

Docker allows easy service isolation and reproducible setups.

  

#### WordPress Stack

  

I also configured:

- lighttpd

- MariaDB

- WordPress

  

WordPress runs at:

```

http://127.0.0.1:4344

```

  

This setup demonstrates hosting a real web service inside the VM.

  

---

  

## Resources

  

- Debian documentation

https://www.debian.org

  

- Learn Linux TV (Bash scripting)

https://www.youtube.com/watch?v=mQP0wqNT_DI

  

- TechWorld with Nana – Virtual Machines

https://www.youtube.com/watch?v=mQP0wqNT_DI

  

- wall command

https://linuxize.com/post/wall-command-in-linux/

  

- LVM checks

https://labex.io/tutorials/linux-how-to-check-if-an-lvm-volume-is-active-in-linux-558783

  

- StackOverflow – CPU usage

- StackExchange – shell scripting

- GitHub – monitoring script inspiration

- AskUbuntu

- Virtual processors explanation

https://community.unix.com/t/number-of-physical-and-virtual-processors/336687/2

  

### AI Usage

  

I used ChatGPT to:

- Explain Linux and system administration concepts

- Help me understand services and design choices

- Support decision-making when I was unsure which service to use

  

All configuration and implementation decisions were done manually to ensure real understanding.