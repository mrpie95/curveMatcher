#include <math.h>

#define MODEL_HEIGHT 1000

#define SIZEOF_X(x)  (sizeof(x) / sizeof((x)[0]))

#define RINSE_MODEL_UPPER  0 
#define RINSE_MODEL_LOWER  1 
#define RINSE_MODEL_SIZE   2
#define RINSE_MODEL_LENGTH 148

int rinse_model = [RINSE_MODEL_SIZE][RINSE_MODEL_LENGTH] = {{1000,1000},{1000,694},{990,694},{985,514},{895,514},{895,481},{895,471},{917,471},{917,438},{917,438},{842,406},{842,406},{887,403},{887,381},{887,381},{865,361},{865,361},{759,342},{759,342},{759,335},{722,328},{722,317},{677,317},{677,323},{677,323},{657,323},{664,323},{664,323},{631,323},{631,328},{631,328},{634,328},{634,339},{642,339},{642,344},{642,344},{642,344},{642,346},{634,346},{634,327},{627,327},{634,321},{642,321},{642,327},{619,327},{619,315},{619,315},{634,309},{634,309},{634,309},{634,309},{634,309},{634,309},{627,315},{627,315},{627,309},{634,309},{634,309},{634,315},{619,315},{619,309},{619,309},{612,309},{597,309},{619,309},{619,309},{612,309},{617,309},{617,309},{610,309},{610,302},{607,302},{597,302},{600,302},{600,302},{600,302},{600,302},{600,302},{610,287},{610,287},{610,273},{610,273},{610,266},{619,266},{610,266},{610,266},{619,266},{619,259},{629,259},{629,245},{629,195},{610,195},{610,75},{629,75},{597,75},{590,30},{600,30},{600,23},{610,23},{590,23},{590,0},{590,0},{582,0},{582,0},{582,0},{582,0},{590,0},{582,0},{582,0},{590,0},{597,0},{604,0},{604,0},{597,0},{597,0},{604,0},{604,0},{627,0},{634,0},{634,0},{634,0},{642,0},{627,0},{627,0},{619,0},{612,0},{612,0},{612,0},{649,0},{664,0},{664,0},{664,0},{649,0},{649,0},{649,0},{642,0},{604,0},{575,0},{575,0},{567,0},{545,0},{545,0},{530,0},{507,0},{455,0},{455,0},{426,0},{418,0}}

int return_larger_int(int a, int b)
{
	if (a > b)
	{
		return a;
	}

	return b; 
}

int return_max(int data[])
{
	int max = 0;

	for (int i = 0; i < SIZEOF_X(data); i++)
	{
		max = return_larger_int(data[i], max_height);
	}

	return max; 
}

void scale_data(int data[])
{
	int height_adj [RINSE_MODEL_LENGTH] = {0};

	int scaled_data [RINSE_MODEL_LENGTH] = {0};

	int drop = ((high_raw*100 - high_raw*11)/100); 

	int max_height = 0;

	max_height = return_max(data);	

	int height_factor = (MODEL_HEIGHT)/max_height;

	int input_data_len = SIZEOF_X(data);

	//scale the height of the graph
	for (int i = 0; i < input_data_len; i++)
	{
		height_adj[i] = data[i] * height_factor;
	}

	//int SIZEOF_X(data)/RINSE_MODEL_LENGTH

	float int height_factor_float = input_data_len/RINSE_MODEL_LENGTH;

	int closest_idx = 0;

	//create a array of the correct size
	for (int i = 0; i < SIZEOF_X(data); i++)
	{
		closest_idx += round(height_factor_float);
		scaled_data[i] = height_adj[closest_idx]
	}




	//to avoid floats: x-xb = (100*x - x*(100b))/100 = (high_raw - high_raw*0.15)
}


bool check_for_rinse(int data[])
{
	bool is_rinse = false;

	int scaled_data = scale_data(data);
	
	int outside_bounds = 0;
	
	int longest_chain  = 0;//longest continous length of data outside the rinse model 
	int current_chain  = 0;//the current length of the 

	for(int i = 0; i < RINSE_MODEL_LENGTH; i++)
	{
		int upper_bound = rinse_model[RINSE_MODEL_UPPER];
		int lower_bound = rinse_model[RINSE_MODEL_LOWER];
		int data_point  = scaled_data[i];

		if ((data_point > upper_bound) || (data_point < lower_bound))
		{
			outside_bounds++;
			current_chain ++; 
		}
		else
		{
			longest_chain = return_larger_int(longest_chain, current_chain);
			current_chain = 0; 
		}
	}

	return is_rinse;
}