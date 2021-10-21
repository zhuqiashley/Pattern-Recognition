#ifndef BOXMULLER
#define BOXMULLER

#include <math.h>
#include <cstdlib>
#include <time.h>

// extern float ranf();         

float ranf()
{
    return (float)rand() / (float)RAND_MAX;
}

// normal random variate generator 
// mean m, standard deviation s 
float box_muller(float m, float s)	
{				        
    float x1, x2, w, y1;
    static float y2;
    static int use_last = 0;

// value from previous call 
    if (use_last)		        
    {
        y1 = y2;
        use_last = 0;
    }
    else
    {
        do {
            x1 = 2.0 * ranf() - 1.0;
            x2 = 2.0 * ranf() - 1.0;
            w = x1 * x1 + x2 * x2;
        } while ( w >= 1.0 );

        w = sqrt( (-2.0 * log( w ) ) / w );
        y1 = x1 * w;
        y2 = x2 * w;
        use_last = 1;
    }

    return( m + y1 * s );
}
#endif
