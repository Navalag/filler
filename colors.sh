# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    colors.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 14:56:18 by agalavan          #+#    #+#              #
#    Updated: 2018/03/05 14:57:20 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

green=$(printf "\e[42m\e[30mO\e[0m")
magenta=$(printf "\e[45m\e[30mX\e[0m")
light_green=$(printf "\e[102m\e[30mo\e[0m")
light_magenta=$(printf "\e[105m\e[30mx\e[0m")
yellow=$(printf "\e[33mplayer\e[0m")

sed "s|O|$green|g" |
sed "s|X|$magenta|g" |
sed "s|x|$light_magenta|g" |
sed "s|o|$light_green|g" |
sed "s|fin|$yellow|g"
