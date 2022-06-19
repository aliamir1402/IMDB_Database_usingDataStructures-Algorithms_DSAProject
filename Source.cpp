//Function 01
	/*	string aname = "Kevin_Spacey";
	for (int i = 0; i < size; i++)
	{
		if (arry[i].actor1_name == aname || arry[i].actor2_name == aname || arry[i].actor3_name == aname)
		{
			int index = HashAlgo(stoi(arry[i].index));
			obj_Movie[index].SearchActor(index, aname);
		}
	}
	quickSort(F02, 0, count_Movie - 1);
	for (int i = 0; i < count_Movie; i++)
	{
		cout << " ActorName: " << aname << " ,Movie Title: " << F02[i].data.mtitle <<
			" ,Year: " << F02[i].data.title_year << endl;
	}
	cout << " Actor: " << aname << " acted in " << count_Movie << " movies." << endl;*/
	//Funtion 02
	/*
	string aname = "Kevin_Spacey";
	for (int i = 0; i < size; i++)
	{
		if (arry[i].actor1_name == aname || arry[i].actor2_name == aname || arry[i].actor3_name == aname)
		{
			int index = HashAlgo(stoi(arry[i].index));
			obj_Movie[index].SearchCoActor(index, aname);
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if ((HTable[i].data.actor_1_name_->data.actor_name == aname ||
			HTable[i].data.actor_2_name_->data.actor_name == aname || HTable[i].data.actor_3_name_->data.actor_name == aname))
		{
			cout <<  " Movie Title: " << HTable[i].data.mtitle
				<< " \nActors: " << HTable[i].data.actor_1_name_->data.actor_name << " \n"
				<< HTable[i].data.actor_2_name_->data.actor_name << " \n"
				<< HTable[i].data.actor_3_name_->data.actor_name << endl;
			cout << endl;
		}
	}
	for (int i = 0; i < count_CoActor; i++)
	{
		cout << " Movie Title: " << F03[i].data.mtitle
			<< " ,\nActors: " << F03[i].data.actor_1_name_->data.actor_name << " \n" << F03[i].data.actor_2_name_->data.actor_name << " \n"
			<< F03[i].data.actor_3_name_->data.actor_name << endl;
		cout << endl;
	}
	*/
	//Funtion 03
/*
	string aname = "Kevin_Spacey";
	for (int i = 0; i < size; i++)
	{
		if (arry[i].actor1_name == aname || arry[i].actor2_name == aname || arry[i].actor3_name == aname)
		{
			int index = HashAlgo(stoi(arry[i].index));
			obj_Movie[index].SearchCoActor1(index, aname);
		}
	}
	string* bname = new string[count_CoActor1];
	string* cname = new string[count_CoActor1];
	for (int i = 0; i < count_CoActor1; i++)
	{
		cout << 'D' << endl;
		if (F041[i].data.actor_1_name_->data.actor_name == aname)
		{
			cout << 'A' << endl;
			bname[i] = F041[i].data.actor_2_name_->data.actor_name;
			cname[i] = F041[i].data.actor_3_name_->data.actor_name;
			for (int i = 0; i < size; i++)
			{
				if (arry[i].actor1_name == bname[i] || arry[i].actor2_name == bname[i] || arry[i].actor3_name == bname[i])
				{
					cout << "b" << endl;
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor2(index, aname);
				}
				if (arry[i].actor1_name == cname[i] || arry[i].actor2_name == cname[i] || arry[i].actor3_name == cname[i])
				{
					cout << "c" << endl;
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor3(index, aname);
				}
			}
		}
		else if (F041[i].data.actor_2_name_->data.actor_name == aname)
		{
			cout << 'B' << endl;

			bname[i] = F041[i].data.actor_1_name_->data.actor_name;
			cname[i] = F041[i].data.actor_3_name_->data.actor_name;
			for (int i = 0; i < size; i++)
			{
				if (arry[i].actor1_name == bname[i] || arry[i].actor2_name == bname[i] || arry[i].actor3_name == bname[i])
				{
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor2(index, aname);
				}
				if (arry[i].actor1_name == cname[i] || arry[i].actor2_name == cname[i] || arry[i].actor3_name == cname[i])
				{
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor3(index, aname);
				}
			}
		}
		else if (F041[i].data.actor_3_name_->data.actor_name == aname)
		{
			cout << 'C' << endl;

			bname[i] = F041[i].data.actor_1_name_->data.actor_name;
			cname[i] = F041[i].data.actor_2_name_->data.actor_name;
			for (int i = 0; i < size; i++)
			{
				if (arry[i].actor1_name == bname[i] || arry[i].actor2_name == bname[i] || arry[i].actor3_name == bname[i])
				{
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor2(index, aname);
				}
				if (arry[i].actor1_name == cname[i] || arry[i].actor2_name == cname[i] || arry[i].actor3_name == cname[i])
				{
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor3(index, aname);
				}
			}
		}
	}
	cout << "A" << endl;
	cout << " Actor A: " << endl;
	for (int i = 0; i < count_CoActor1; i++)
	{
		cout << " SearchName: " << aname << " ,Movie Title: " << F041[i].data.mtitle
			<< " ,Actors: " << F041[i].data.actor_1_name_->data.actor_name << " \n"
			<< F041[i].data.actor_2_name_->data.actor_name << " \n"
			<< F041[i].data.actor_3_name_->data.actor_name << endl;
	}
	cout << " Actor B: " << endl;
	for (int i = 0; i < count_CoActor2; i++)
	{
		cout << " SearchName: " << bname[i] << " ,Movie Title: " << F042[i].data.mtitle
			<< " ,Actors: " << F042[i].data.actor_1_name_->data.actor_name << " \n"
			<< F042[i].data.actor_2_name_->data.actor_name << " \n"
			<< F042[i].data.actor_3_name_->data.actor_name << endl;
	}
	cout << " Actor C: " << endl;
	for (int i = 0; i < count_CoActor3; i++)
	{
		cout << " SearchName: " << cname[i] << " ,Movie Title: " << F043[i].data.mtitle
			<< " ,Actors: " << F043[i].data.actor_1_name_->data.actor_name << " \n"
			<< F043[i].data.actor_2_name_->data.actor_name << " \n"
			<< F043[i].data.actor_3_name_->data.actor_name << endl;
	}

	for (int i = 0; i < count_CoActor1; i++)
	{
		if (F041[i].data.actor_1_name_->data.actor_name == aname || F041[i].data.actor_2_name_->data.actor_name
			== aname || F041[i].data.actor_3_name_->data.actor_name == aname)
		{
			int index = HashAlgo(stoi(F041[i].data.index));
			obj_Movie[index].SearchCoActor(index, aname);
		}
	}

	for (int i = 0; i < count_CoActor1; i++)
	{
		if ((arry[i].actor1_name == F041[i].data.actor_1_name_->data.actor_name)
			&& (F041[i].data.actor_1_name_->data.actor_name != aname) ||
			(arry[i].actor2_name == F041[i].data.actor_2_name_->data.actor_name)
			&& (F041[i].data.actor_2_name_->data.actor_name != aname) ||
			(arry[i].actor3_name == F041[i].data.actor_3_name_->data.actor_name)
			&& (F041[i].data.actor_3_name_->data.actor_name != aname))
		{
			int index = HashAlgo(stoi(arry[i].index));
			obj_Movie[index].SearchCoActor2(index, aname);
		}
		else if ((arry[i].actor2_name == F041[i].data.actor_2_name_->data.actor_name)
			&& (F041[i].data.actor_1_name_->data.actor_name != aname));
	}
*/
//Function 04
//SearchTwoActorsInMovie(arry, arry, arry, "Luke_Edwards", "Bree_Williamson");
//FOR FUNCTION 07
	/* {
			cout << " Movies Names " << endl << endl;;
			for (int j = 1; j < 8; j++)
				obj_Movie[j].SearchMovieWithDirector(j, "Bob_Clark");
			cout << endl << " These Are The Movies \"Bob_Clark\" Directed." << endl;
		}
		*/
		//Function 08
		/*PrintDirectorsGenre("War", arr);*/
			//Function 9
			/* int option;
				cout<<" Enter Option For Order:\n 0:Increasing Order\n 1:Decreasing Order\n";cin>>option;
				for (int i = 1; i < 8; i++)
					obj_Movie[i].PrintYearWise(i);
				cout << endl;
				for (int i = 0; i < size; i++)
					cout << "Index " << i+1 << ": " << F12[i].data.mtitle << endl;
				cout << " Counter: " << counter << endl;
				quickSort(F12, 0, size - 1,option);
				cout << endl;
				cout<<" List of Movies Sorted Yearly: "<<endl;
				for (int i = 0; i < size; i++)
					cout << "Index " << i + 1 << ": " << F12[i].data.mtitle << endl;
			*/
			//Function 10
		   /*  PrintMoviesGernes(arr, "War");
			 quickSort__(F11, 0, count__ - 1);
			 cout << " Movies Sorted According to Rating Based on Genre: " << endl;
			 for (int i = 0; i < count__; i++)
			 {
				 cout << " Movie Name: " << F11[i].tmovie << ", Rating: " << F11[i].imdb_score << endl;
			 }*/
			 //For Function 11
			 /*	for (int i = 1; i < 8; i++)
						 obj_Movie[i].PrintMovieRatingWise(i);
					 cout << endl;
					 for (int i = 0; i < size; i++)
						 cout << "Index " << i+1 << ": " << F12[i].data.mtitle << endl;
					 cout << " Counter: " << counter << endl;
					 quickSort(F12, 0, size - 1);
					 cout << endl;
					 for (int i = 0; i < size; i++)
						 cout << "Index " << i + 1 << ": " << F12[i].data.mtitle << endl;
				 */
/*
void swaps1(Array* a, Array* b)
{
	Array t = *a;
	*a = *b;
	*b = t;
}
int partitions1(Array arr[], int low, int high)
{
	Array a, b, c, d;
	string pivot = arr[high].actor1_name; // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if ((arr[j].actor1_name) < pivot)
		{
			i++; // increment index of smaller element 
			a = arr[i];
			b = arr[j];
			swaps1(&a, &b);
			arr[i] = a;
			arr[j] = b;
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swaps1(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSorts1(Array arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		//int pi = partitions1(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
	/*	quickSorts1(arr, low, pi - 1);
		quickSorts1(arr, pi + 1, high);
	}
}
void swaps2(Array* a, Array* b)
{
	Array t = *a;
	*a = *b;
	*b = t;
}
int partitions2(Array arr[], int low, int high)
{
	Array a, b, c, d;
	string pivot = arr[high].actor1_name; // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if ((arr[j].actor2_name) < pivot)
		{
			i++; // increment index of smaller element 
			a = arr[i];
			b = arr[j];
			swaps2(&a, &b);
			arr[i] = a;
			arr[j] = b;
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swaps2(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSorts2(Array arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		/**int pi = partitions2(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSorts2(arr, low, pi - 1);
		quickSorts2(arr, pi + 1, high);
	}
}*/
/*
void swaps3(Array* a, Array* b)
{
	Array t = *a;
	*a = *b;
	*b = t;
}
int partitions3(Array arr[], int low, int high)
{
	Array a, b, c, d;
	string pivot = arr[high].actor1_name; // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if ((arr[j].actor3_name) < pivot)
		{
			i++; // increment index of smaller element 
			a = arr[i];
			b = arr[j];
			swaps3(&a, &b);
			arr[i] = a;
			arr[j] = b;
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swaps3(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSorts3(Array arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		//int pi = partitions3(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
	/*	quickSorts3(arr, low, pi - 1);
		quickSorts3(arr, pi + 1, high);
	}
}
*/