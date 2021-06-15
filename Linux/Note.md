# Directory and File
- **cd** ~ : �^��a�ؿ�
- **cd *~[account]*** : ��*[account]*���a�ؿ�
- **cd**  : �^��a�ؿ�
- **cd** .. : �e���W�h�ؿ�
- **cd** - : �^��W�@�ӥؿ�

- `.` : �N���e�ؿ�
- `..` : �N��W�@�h�ؿ�
- **pwd *[-P]*** : ��ܥثe�Ҧb���ؿ��F *-P* �G ��ܥX�T�ꪺ���|�A�ӫD�ϥγs�� (link) ���|
- **mkdir *[-mp]***: *-m* : �]�w�v��(e.g. 711)�F*-p* : ���j�ާ@(��h)
- **rmdir *[-p]*** : �R���u�šv�ؿ��F*-p* : ���j�ާ@

- **cp *[-a][-r][-i] [from] [to]*** : �ƻs�ɮ�(�ؿ�)�F*-a* : �򥻤W�N��ƻs���ɮת��@��(�]�A�v��) �F*r* : ���j�ƻs(�Ω�ؿ�)�F*-i* : �X�{ĵ�i�T��
- **touch *[file]*** : �إߪ��ɮ�
- **rm *[-i][-r]*** : �R���ɮ�(�ѼƷN�q�P cp)
- **mv *[-i] [from(name A)] [to (name B)]*** : ���ʡB���s�R�W�ɮ�
- �ɦW�� "`-`" ���ɮ׭n�ε�����|�Ӷ}�ҡG`./-`
- �ɦW���ť���G`vi "a file with spaces"`
- `file [filename]`: ����ɮ����� (dat, ASCII, etc)
- `find [-specifics]` : ��M��e�M�l�ؿ����ŦX�����ɮ�(�ؿ�)
    - `find -size 1033c`: �j�p��`1033 byte`���ɮ�
    - `find -user [owner] -group [group name]` : �ɮ׾֦��̤θs��
    - `find [-...] 2>/dev/null` : �ư��]�v���L�k�s�����ɮ�
- `wc [file1] [file2]` : ��X�ɮת�����ơB�r�ƻP�줸�ռ�
    - `wc -l` : �����
    - `wc -w` : �r��
    - `wc -c` : �줸�ռ�
    - `wc -m` : �r����
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
# Others
- `sort [file]` : Sort the given file
- `strings [file]` : Prints the printable character sequences that are at least 4 characters long
- `grep [pattern] [file1/dir1] [file2/dir2]` : Find contents/files that matches the pattern
- `uniq [file]` :  Filter adjacent matching lines 

