if status is-login
    if test -z "$DISPLAY" -a "$XDG_VTNR" = 1
        exec startx -- -keeptty
    end
end

## PATH
set PATH /home/av/.local/bin /home/av/.cargo/bin $PATH

alias ls="lsd"
alias vi="nvim"
alias svi='sudo nvim'
alias vis='nvim "+set si"'
alias xm="xmodmap ~/.Xmodmap"
alias gp="git push"
alias gc="git clone"
alias upd="sudo pacman -Syu --noconfirm"
alias m="sudo make clean install"
alias q="exit"
alias c="clear"
if status is-interactive
	  oh-my-posh init fish --config ~/.config/fish/themes/gruvbox.omp.json | source
	end
