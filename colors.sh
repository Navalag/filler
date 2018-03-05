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

blue=$(printf "\033[36mO\033[0m")
yellow=$(printf "\033[33mX\033[0m")
green=$(printf "\033[32mo\033[0m")
red=$(printf "\033[31mx\033[0m")

sed "s|O|$blue|g" |
sed "s|X|$yellow|g" |
sed "s|x|$red|g" |
sed "s|o|$green|g" |
sed "s|fin|player|g"
