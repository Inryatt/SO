#!/bin/bash
# select structure to create menus
PS3="Selecione uma das opçoes sff: "
select arg in $@; do
    if [[ $arg != $@ ]]; then
        echo "Opção não válida."
        break
    fi
    echo "You picked $arg ($REPLY)."
done