#include <stdio.h>
#include <math.h>

#define PI (3.14159)
double caculateCylinder(double w, double h);

int main(void)
{
	double width, height;
	double max_volume;

	while(scanf("%lf %lf", &width, &height) == 2 &&
		(width > 0 && height > 0))
	{
		max_volume = caculateCylinder(width, height);
		printf("%.3lf\n", max_volume);
	}
	return 0;
}

double caculateCylinder(double w, double h)
{
	double volume = 0.0, tmp_volume;
	double radius = 0.0;

	/*
	** tailor the height
	** 2 * PI * radius == width
	** or
	** 2 * PI * radius == height - 2 * radius
	*/
	radius = w / (2 * PI);
	if(2 * radius < h)
	{
		/*
		** for 2 * PI * radius == width
		** can cut out two bottoms
		*/
		volume = PI * radius * radius * (h - 2 * radius);
	}
	else
	{
		/*
		** 2 * radius = 
	}


	radius = h / (2 * PI + 2);
	if(2 * radius <= w)
	{
		/*
		** for 2 * PI * radius == height - 2 * radius
		** can cut out two bottoms
		*/
		tmp_volume = PI * radius * radius * w;
		if(tmp_volume > volume)
		{
			volume = tmp_volume;
		}
	}

	/*
	** tailor the width
	** 2 * PI * radius == height
	** or
	** 2 * PI * radius == width - 2 * radius
	*/
	radius = h / (2 * PI);
	if(2 * radius <= h && 2 * radius < w)
	{
		/*
		** for 2 * PI * radius == height
		** can cut out two bottoms
		*/
		tmp_volume = PI * radius * radius * (w - 2 * radius);
		if(tmp_volume > volume)
		{
			volume = tmp_volume;
		}
	}

	radius = w / (2 * PI + 2);
	if(2 * radius <= h)
	{
		/*
		** for 2 * PI * radius == w - 2 * radius
		** can cut out two bottoms
		*/
		tmp_volume = PI * radius * radius * h;
		if(tmp_volume > volume)
		{
			volume = tmp_volume;
		}
	}

	return volume;
}