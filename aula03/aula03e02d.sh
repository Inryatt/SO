#|/bin/bash
#tecnicamente e a alinea e mas fica melhor assim

if (( $1 > 5 )) ; then
	if (( $1 < 10 )) ; then
		echo "Numero maior do que cinco e menor do que 10."
	fi
fi
