export JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk1.8.0_181.jdk/Contents/Home
export PATH=$JAVA_HOME/bin:$PATH
export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
export EDITOR=vim

#enables colorin the terminal bash shell export

if [ -f "./.bashrc" ]; then
source ./.bashrc
fi

export CLICOLOR=1

#sets up thecolor scheme for list export

export LSCOLORS=gxfxcxdxbxegedabagacad

#sets up theprompt color (currently a green similar to linux terminal)

export PS1='\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;36m\]\W\[\033[00m\]\$ '

#enables colorfor iTerm

export TERM=xterm-color


#my alias option
alias ll='ls -l'
alias la='ls -a'
alias llh='ls -lh'
alias lla='ls -al'
alias mv="mv -i"
alias rm='rm -i'
alias g++='g++ -std=c++11'
alias rg++='g++'
alias ssh100='ssh 192.168.1.100 -l root'
alias ssh101='ssh 192.168.1.101 -l root'
alias ssh102='ssh 192.168.1.102 -l root'
export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.tuna.tsinghua.edu.cn/homebrew-bottles
export GOPATH=/Users/huguang/go

test -e "${HOME}/.iterm2_shell_integration.bash" && source "${HOME}/.iterm2_shell_integration.bash"

