#!/nix/store/rdd4pnr4x9rqc9wgbibhngv217w2xvxl-bash-interactive-5.2p26/bin/bash
HISTFILE=${HISTFILE:-~/.bash_history} #gets the bash history
set -o history #enables history tracking
history | tail -n 8
#gives the last 8 commands
