#yaad

import subprocess as sub

pwd = 'qazwsxqazwsx'
cmd = 'lspci -vv'

sub.call(['echo {} | sudo -s {}'.format(pwd,cmd)],stdout=open('hello.txt','w'),shell=True)
