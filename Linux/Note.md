# Directory and File
- `cd` ~ : �^��a�ؿ�
- `cd ~[account]` : ��[account]���a�ؿ�
- `cd`  : �^��a�ؿ�
- `cd` .. : �e���W�h�ؿ�
- `cd` - : �^��W�@�ӥؿ�

- `.` : �N���e�ؿ�
- `..` : �N��W�@�h�ؿ�
- `pwd [-P]` : ��ܥثe�Ҧb���ؿ��F `-P` �G ��ܥX�T�ꪺ���|�A�ӫD�ϥγs�� (link) ���|

- `mkdir [-mp]`: -m : �]�w�v��(e.g. 711)�F`-p` : ���j�ާ@(��h)
- `rmdir [-p]` : �R���u�šv�ؿ��F`-p` : ���j�ާ@

- `cp [-a][-r][-i] [from] [to]` : �ƻs�ɮ�(�ؿ�)�F`-a` : �򥻤W�N��ƻs���ɮת��@��(�]�A�v��) �F`-r` : ���j�ƻs(�Ω�ؿ�)�F`-i` : �X�{ĵ�i�T��
- `touch [file]` : �إߪ��ɮ�
- `rm [-i][-r]` : �R���ɮ�(�ѼƷN�q�P `cp`)
- `mv [-i] [from(name A)] [to (name B)]` : ���ʡB���s�R�W�ɮ�
- `chgrp [-R] [group] [file/dir]` : ���s�� (root)
- `chown [-R] [user:group] [file/dir]` : ���֦��� (�s�դ]�i�H : `user:group`) (root)
- `chmod [-R] [xyz] [file/dir]` : �ɮ��v����� 
    - `r` : 4
    - `w` : 2
    - `x` : 1

    >*e.g. `chmod -R 720 myfile`*
- �ɦW�� "`-`" ���ɮ׭n�ε�����|�Ӷ}�ҡG`./-`
- �ɦW���ť���G`vi "a file with spaces"`
- `file [filename]`: ����ɮ����� (*dat, ASCII, etc*)
- `find [-specifics]` : ��M��e�M�l�ؿ����ŦX�����ɮ�(�ؿ�)
    - `find -size 1033c`: �j�p��`1033 byte`���ɮ�
    - `find -user [owner] -group [group name]` : �ɮ׾֦��̤θs��
    - `find [-...] 2>/dev/null` : �ư��]�v���L�k�s�����ɮ�
- `wc [file1] [file2]` : ��X�ɮת�����ơB�r�ƻP�줸�ռ�
    - `wc -l` : �����
    - `wc -w` : �r��
    - `wc -c` : �줸�ռ�
    - `wc -m` : �r����
## Compression / Archive File
- `gzip [-c] [file]` : To compress file to `.gz`
    - `-c` : to decompress and output on STDOUT (equivalent to `zcat [file]`)
- `bzcat [file]` : decompress `.bzip` 
- `tar [-cxfv] [file]` : 
    >`tar` is a computer software utility for collecting many files into one *archive file*, not for compressing files
    - `-c` : create a new `.tar` file
    - `-x` : extract a `.tar` file
    - `-f` : designate a file, otherwise STDIN
    - `-v` : more detailed listing (for even more :  `-vv`)
# Streams
>Every program you may run on the command line has 3 streams, STDIN, STDOUT and STDERR.
- `STDIN [0]`
- `STDOUT [1]`
- `STDERR [2]`
    > Note: `cat -` means reading STDIN(user input) for `cat`

## Redirection
- `>` : Save output to a file.
- `>>` : Append output to a file.
- `<` : Read input from a file.
- `2>` : Redirect error messages.
    - `2>&1` : redirect `STDERR[2]` to `STDOUT[1]`
    > If there isn't `&`, `2>1` will be identified as redirecting to a file naming '1'

## Piping
- `|` : Send the output from left program as input to right program.
    - `cat data.txt | sort | uniq -u`
# Encode / Decode
-  `base64 [file] [-d]` : Encode file with base64 (`-d` to decode)
- `tr [options] [str1] [str2]` :
    - `str1` : translate from
    - `str2` : : translate to
    > Note: characters are corresponded one-by-one between `str1` and `str2`
    
    >*e.g. `tr a-zA-Z n-za-mN-ZA-M`* : Rot13 encoding
# Netcat (nc)
- `nc [-vul] [host] [port]` : using the `TCP` or `UDP` protocols to read or write data 
    - `-v` : verbose message displayed
    - `-u` : use `UDP` instead of `TCP`
    - `-l` : listen for an incoming connection rather than initiating a connection to a remote host
    > *e.g. `echo "Hi" | nc -u localhost 8000`* : transmit a `UDP` packet

    > *e.g. `nc -lu localhost 8000`* : accept a packet under `UDP`
# SSH 
- `ssh <user>@<host> [-p [port] ]` : login `host` 
- `ssh-keygen -t rsa` : generate `RSA` key under `.ssh/`
# Others
- `sort [file]` : Sort the given file
- `strings [file]` : Prints the printable character sequences that are at least 4 characters long
- `grep [pattern] [file1/dir1] [file2/dir2]` : Find contents/files that matches the pattern
- `uniq [file]` :  Filter adjacent matching lines 


