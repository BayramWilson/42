# Born2beRoot – Evaluation Cheat Sheet

## Clone & Preliminaries
```bash
git clone <repo_url>
```
```bash
ls -la
```
```bash
sha1sum <vm_name>.vdi
```
```bash
cat signature.txt
```
```bash
diff signature.txt <(sha1sum <vm_name>.vdi | awk '{print $1}')
```

## System & OS
```bash
uname -a
```
```bash
cat /etc/os-release
```
```bash
hostname
```
```bash
hostnamectl
```
```bash
sudo hostnamectl set-hostname yourlogin42
```
```bash
reboot
```

## Users & Groups
```bash
cat /etc/passwd
```
```bash
groups
```
```bash
getent group sudo
```
```bash
getent group user42
```
```bash
sudo adduser testuser
```
```bash
sudo usermod -aG sudo,user42 testuser
```
```bash
sudo groupadd evaluating
```
```bash
sudo usermod -aG evaluating testuser
```
```bash
groups testuser
```

## Password Policy
```bash
cat /etc/login.defs
```
```bash
cat /etc/pam.d/common-password
```
```bash
chage -l testuser
```

## SUDO
```bash
sudo -V
```
```bash
which sudo
```
```bash
sudo visudo
```
```bash
ls /etc/sudoers.d/
```
```bash
ls /var/log/sudo/
```
```bash
cat /var/log/sudo/*
```
```bash
sudo ls /root
```

## Partitions & LVM
```bash
lsblk
```
```bash
lsblk -f
```
```bash
df -h
```
```bash
mount
```
```bash
pvdisplay
```
```bash
vgdisplay
```
```bash
lvdisplay
```

## Firewall (UFW / firewalld)

### Debian (UFW)
```bash
sudo ufw status verbose
```
```bash
sudo ufw allow 8080
```
```bash
sudo ufw delete allow 8080
```

### Rocky (firewalld)
```bash
sudo firewall-cmd --state
```
```bash
sudo firewall-cmd --list-all
```
```bash
sudo firewall-cmd --add-port=8080/tcp
```
```bash
sudo firewall-cmd --remove-port=8080/tcp
```

## SSH
```bash
systemctl status ssh
```
```bash
systemctl status sshd
```
```bash
grep -E "Port|PermitRootLogin" /etc/ssh/sshd_config
```
```bash
ssh testuser@localhost -p 4242
```

## Monitoring Script / Cron
```bash
find / -name "*.sh" 2>/dev/null
```
```bash
crontab -l
```
```bash
sudo crontab -l
```
```bash
ls /etc/cron.*
```
```bash
cat /etc/crontab
```
```bash
journalctl -u cron
```

## General Debug
```bash
journalctl -b
```
```bash
dmesg
```
```bash
du -sh /*
```
