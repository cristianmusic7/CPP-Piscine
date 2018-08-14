/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rect.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:23:56 by jpollore          #+#    #+#             */
/*   Updated: 2018/07/01 20:25:10 by jpollore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RECT_CLASS_HPP
# define RECT_CLASS_HPP

class	Rect
{
	public:
		Rect(int offset_x, int offset_y, int bounds_x, int bounds_y);
		~Rect();
		Rect(Rect const & ref);

		Rect&		operator=(Rect const & rhs);

		int		top() const;
		int		bot() const;
		int		left() const;
		int		right() const;

		int		width() const;
		int		height() const;

		int		getOffsetX() const;
		int		getOffsetY() const;
		int		getBoundsX() const;
		int		getBoundsY() const;
	
	private:
		Rect();

		int		_offset_x;
		int		_offset_y;
		int		_bounds_x;
		int		_bounds_y;
};

#endif // RECT_CLASS_HPP
