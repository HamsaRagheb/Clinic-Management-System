#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Structs.h"

/******************** Prototype Of Functions ********************/
void Main_Minue();
void features();
void Add_Patient();
u8 Unique_ID(u16 entered_id);
void Print_Data();
void Edit_Patient();
u8 Check_ID(u16 entered_id);
void Reservation();
u8 UniqueSlotForID(u16 ID);
void Reserve_A_Slot(u8 Time[], u16 entered_id);
void Slots();
u8 Print_Available_Slots();
void Cancel_Reservation();
void User();
void Print_PatientRecord(u16 id);
void Today_Reservation();

/******************** Head Pointers of Two Structs ********************/
patient_node *Head = NULL;
reservation *head = NULL;

/******************** Main Function ********************/
void main(void)
{
	printf("\n************************************ WELCOME TO OUR CLINIC :) ^_^ *************************************");

	Slots();	  // Calling of Slots Function To Creat The Slots
	Main_Minue(); // Calling of Main Minue Function
}
/******************** Main Minue Function ********************/
void Main_Minue()
{
	u8 mode, i, flag = 1;
	u16 pass = 0;

	while (flag == 1)
	{
		printf("\n-----------------------------------------------------------------------------------\n");
		printf("Enter 1 For Admin Mode\nEnter 2 For User Mode\nEnter 3 To Exist From The Program\n");
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
			printf("\nPlease Enter The Password : ");
			for (i = 0; i < 3; i++)
			{
				scanf("%d", &pass);
				if (pass == 1234)
				{
					printf("\n******************************************** Admin Mode **********************************************\n");
					features();
					break;
				}
				else if (i < 2)
				{
					printf("Incorrect Password!Try Again . \n");
				}
			}
			if (i > 2)
			{
				printf("Incorrect Password for 3 consecutive times!, No more tries\n");
			}
			break;
		case 2:
			printf("\n********************************************** User Mode **********************************************\n");
			User();
			break;
		case 3:
			break;

		default:
			printf("Invalide Mode!, Try Again\n");
			flag = 1;
			break;
		} // for switch(mode)
	}	  // for while(flag==1)
}

/************* features Function to Display All Features that the Admin Can make ***************/
void features()
{
	u8 choose, flag = 1, id;

	while (flag == 1)
	{
		printf("\nEnter 1 To Add New Patient Record :\nEnter 2 To Edit Patient Record : \nEnter 3 To Reserve A Slot With The Doctor :\nEnter 4 To Cancel Reservation :\nEnter 5 To See The Data Of all Patients in the Order : \nEnter 6 To Go To The Main Minue :\n");
		scanf("%d", &choose);
		printf("\n");
		switch (choose)
		{
		case 1:
			printf("\n-------------------------------------------------------------\n");
			Add_Patient();
			printf("\n**************** Adding New Patient Is Done Successfully. **************************************\n");
			printf("****************** Thank You *********************************");
			printf("\n-------------------------------------------------------------\n");
			flag = 1;
			break;

		case 2:
			printf("\n-------------------------------------------------------------\n");
			Edit_Patient();
			printf("\n-------------------------------------------------------------\n");
			flag = 1;
			break;

		case 3:
			Reservation();
			flag = 1;
			break;
		case 4:
			Cancel_Reservation();
			flag = 1;
			break;

		case 5:
			Print_Data();
			flag = 1;
			break;

		case 6:
			Main_Minue();
			break;

		default:
			printf("Invalid Choose!Try Again.\n");
			flag = 1;
			break;

		} // for switch (choose)
	}	  // for while( flag == 1 )
}
/******************** Add_Patient Function To Add New Patient ********************/
void Add_Patient()
{
	patient_node *new_patient = (patient_node *)malloc(sizeof(patient_node));
	patient_node *last = NULL;

	printf("Please Enter Your Name : ");
	scanf("%s", &new_patient->name);
	printf("Please Enter Your Age : ");
	scanf("%d", &new_patient->age);
	printf("Please Enter Your Gender : ");
	scanf("%s", &new_patient->gender);
	printf("Please Enter Your ID : ");
	while (1)
	{
		scanf("%d", &new_patient->id);
		if (Unique_ID(new_patient->id))
		{
			if (Head == NULL)
			{
				Head = new_patient;
				new_patient->next = NULL;
			}
			else
			{
				last = Head;
				while (last->next != NULL)
				{
					last = last->next;
				}
				last->next = new_patient;
				new_patient->next = NULL;
			}
			break;
		}
		else
		{
			printf("\nThis ID is already exist, Please Enter another ID : ");
		}
	} // for while(1)
}
/****************** Unique_ID Function To Check if The ID Unique Or Not ****************/
u8 Unique_ID(u16 entered_id)
{
	patient_node *ptr = NULL;
	u8 flag = 0;
	if (Head == NULL)
	{
		return 1; /// First Patient, There's no problem in first ID
	}
	else
	{
		ptr = Head;
		while (ptr != NULL && ptr->id != entered_id)
		{
			ptr = ptr->next;
		}
		if (ptr != NULL)
		{
			return 0; /// Not Unique_ID
		}
		else
		{
			return 1; /// Unique_ID
		}
	}
}
/******************** Check_ID Function To Check if The ID Correct Or Not ******************/
u8 Check_ID(u16 entered_id)
{
	patient_node *ptr = NULL;
	u8 flag = 0;
	ptr = Head;
	while (ptr != NULL)
	{
		if (ptr->id == entered_id)
		{
			flag = 1; /// Whene flag=1, this mean that there is an id in my linkedList equal to this entered_id
			break;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		return flag; /// Not Valid ID
	}
	else
	{
		return flag; /// Valid ID
	}
}

/******************** Edit_Patient Function To Edit The Patient Record ********************/
void Edit_Patient()
{
	u8 entered_ID, flag = 1, choose;
	patient_node *ptr = NULL;

	if (Head == NULL)
	{
		printf("No patients yet to Edit!\n");
	}
	else
	{
		printf("Please Enter Patient ID : ");
		scanf("%d", &entered_ID);
		if (Check_ID(entered_ID))
		{
			// Print_PatientRecord(entered_ID);
			ptr = Head;
			while (ptr != NULL && ptr->id != entered_ID)
			{
				ptr = ptr->next;
			}
			if (ptr != NULL)
			{
				printf("New Data : \n");
				printf("Please Enter New Name : ");
				scanf("%s", &ptr->name);
				printf("Please Enter New Age : ");
				scanf("%d", &ptr->age);
				printf("Please Enter New Gender : ");
				scanf("%s", &ptr->gender);
				printf("Please Enter New ID : ");
				scanf("%d", &ptr->id);
				printf("\n******************************* The Data has been Edited Successfully *******************************\n");
				printf("****************** Thank You *********************************");
			} // for if(ptr != NULL)
			else
			{
			}
		} // for if(Check_ID(entered_ID))
		else
		{
			printf("Incorrect ID!\n");
		}
	} // for if(Head != NULL)
}
/******************** Print_Data Function To Display The Data Of all Patients in the Order ********************/
void Print_Data()
{
	printf("\n-------------------------------------------------------------\n");

	patient_node *GenPtr = NULL;
	u8 counter = 1;

	if (Head == NULL)
	{
		printf("No patients yet!\n");
		printf("\n-------------------------------------------------------------\n\n");
	}
	else
	{
		GenPtr = Head;
		while (GenPtr != NULL)
		{
			printf("Patient Number %d it's Data :-\nName: %s\t\t", counter, GenPtr->name);
			printf("Age: %d\t\t", GenPtr->age);
			printf("Gender: %s\t\t", GenPtr->gender);
			printf("ID: %d\t\n", GenPtr->id);
			printf("\n-------------------------------------------------------------\n");
			GenPtr = GenPtr->next;
			counter++;
		}
	}
}
/******************** Print_PatientRecord Function To Print Patient Record *******************/
void Print_PatientRecord(u16 id)
{
	patient_node *ptr = NULL;
	ptr = Head;
	while (ptr != NULL && ptr->id != id)
	{
		ptr = ptr->next;
	}
	if (ptr != NULL)
	{
		printf("\n-------------------------------------------------------------\n");
		printf("Patient's Data :-\nName: %s\t\t", ptr->name);
		printf("Age: %d\t\t", ptr->age);
		printf("Gender: %s\t", ptr->gender);
		printf("ID: %d\t\n", ptr->id);
		printf("\n-------------------------------------------------------------\n");
	}
}
/****************** Reservation Function To Reserve Slots with The Doctor *****************/
void Reservation()
{
	printf("\n-------------------------------------------------------------------\n");

	u8 choose, entered_id, slot, flag = 1;
	if (Head != NULL)
	{
		printf("\n************ Available Slots Are ************\n\n");
		slot = Print_Available_Slots();
		if (slot == 1)
		{
			while (flag == 1)
			{
				printf("Enter The Letter Of The Slot That You Wanted To Reserve : ");
				scanf(" %c", &choose);
				printf("\n");
				switch (choose)
				{
				case 'A':
				case 'a':
					printf("Please Enter Your ID : ");
					scanf("%d", &entered_id);
					if (Check_ID(entered_id) == 1)
					{
						Reserve_A_Slot("2:00 PM To 2:30 PM", entered_id);
						features();
					}
					else
					{
						printf("Incorrect ID!\n");
						features();
					}
					break;
				case 'B':
				case 'b':
					printf("Please Enter Your ID : ");
					scanf("%d", &entered_id);
					if (Check_ID(entered_id) == 1)
					{
						Reserve_A_Slot("2:30 PM To 3:00 PM", entered_id);
						features();
					}
					else
					{
						printf("Incorrect ID!\n");
						features();
					}

					break;
				case 'C':
				case 'c':
					printf("Please Enter Your ID : ");
					scanf("%d", &entered_id);
					if (Check_ID(entered_id) == 1)
					{
						Reserve_A_Slot("3:00 PM To 3:30 PM", entered_id);
						features();
					}
					else
					{
						printf("Incorrect ID!\n");
						features();
					}
					break;
				case 'D':
				case 'd':
					printf("Please Enter Your ID : ");
					scanf("%d", &entered_id);
					if (Check_ID(entered_id) == 1)
					{

						Reserve_A_Slot("4:00 PM To 4:30 PM", entered_id);
						features();
					}
					else
					{
						printf("Incorrect ID!\n");
						features();
					}
					break;
				case 'E':
				case 'e':
					printf("Please Enter Your ID : ");
					scanf("%d", &entered_id);
					if (Check_ID(entered_id) == 1)
					{
						Reserve_A_Slot("4:30 PM To 5:00 PM", entered_id);
						features();
					}
					else
					{
						printf("Incorrect ID!\n");
						features();
					}
					break;
				default:
					printf("Incorrect Choose! Please Try Again : \n\n");
					flag = 1;
				} // for switch(choose)
			}	  // for while(flag==1)

		} // for if(slot == 1 )
		else if (slot == 0)
		{
			printf("********************** Sorry!,No Slots Are Avaliable Now. **********************\n");
			printf("\n-------------------------------------------------------------------\n");
			features();
		}
	} // for if(Head != NULL)
	else if (Head == NULL)
	{
		printf("No patients yet to Reserve A Slot!\n");
	}
	printf("\n-------------------------------------------------------------------\n");
}

/******************** Slots Function To Creat Slots with The Doctor ********************/
void Slots()
{
	head = (reservation *)malloc(sizeof(reservation));
	reservation *slot2 = (reservation *)malloc(sizeof(reservation));
	reservation *slot3 = (reservation *)malloc(sizeof(reservation));
	reservation *slot4 = (reservation *)malloc(sizeof(reservation));
	reservation *slot5 = (reservation *)malloc(sizeof(reservation));

	strcpy(head->time, "2:00 PM To 2:30 PM");
	head->id = 0;
	head->next = slot2;

	strcpy(slot2->time, "2:30 PM To 3:00 PM");
	slot2->id = 0;
	slot2->next = slot3;

	strcpy(slot3->time, "3:00 PM To 3:30 PM");
	slot3->id = 0;
	slot3->next = slot4;

	strcpy(slot4->time, "4:00 PM To 4:30 PM");
	slot4->id = 0;
	slot4->next = slot5;

	strcpy(slot5->time, "4:30 PM To 5:00 PM");
	slot5->id = 0;
	slot5->next = NULL;
}

/***************** Print_Available_Slots Function Print The Available Slots that The Admin Can Reserve  *****************/
u8 Print_Available_Slots()
{
	reservation *GenPtr = NULL;
	u8 counter = 'A', flag;
	GenPtr = head;
	while (GenPtr != NULL)
	{
		if (GenPtr->id == 0)
		{
			printf("%c - %s \n", counter, GenPtr->time);
			flag = 1;
		}
		GenPtr = GenPtr->next;
		counter++;
	}
	if (flag == 1)
	{
		return flag;
	}
	else
	{
		return flag;
	}
}
/****************** UniqueSlotForID Function To Check if The ID has more than slot with The Doctor ******************/
u8 UniqueSlotForID(u16 ID)
{
	reservation *ptr = NULL;
	ptr = head;
	while (ptr != NULL && ptr->id != ID)
	{
		ptr = ptr->next;
	}
	if (ptr != NULL)
	{
		return 0; // This ID has already a Slot
	}
	else
	{
		return 1; // New Slot
	}
}

/******************** Reserve_A_Slot Function To Make The Reservation ********************/
void Reserve_A_Slot(u8 Time[], u16 entered_id)
{
	reservation *GenPtr = NULL;
	if (UniqueSlotForID(entered_id))
	{
		GenPtr = head;
		while (GenPtr != NULL && strcmp(GenPtr->time, Time) != 0)
		{
			GenPtr = GenPtr->next;
		}
		if (GenPtr != NULL)
		{
			GenPtr->id = entered_id;
		}
		printf("\n*********************** Reservation Is Done Successfully ***********************\n");
		printf("********************** Thank You *********************************\n");
		printf("-------------------------------------------------------------------\n\n");
	}
	else
	{
		printf("\n**************************** This ID has already Slot with The Doctor ****************************\n");
		printf("\n-------------------------------------------------------------------\n\n");
	}
}

/******************** Cancel_Reservation Function To Cancel The Reservation ********************/
void Cancel_Reservation()
{
	u16 entered_id;
	reservation *ptr = NULL;
	if (Head != NULL)
	{
		printf("Please Enter Your ID : ");
		while (1)
		{
			scanf("%d", &entered_id);
			if (Check_ID(entered_id) == 1)
			{
				ptr = head;
				while (ptr != NULL && ptr->id != entered_id)
				{
					ptr = ptr->next;
				}
				if (ptr != NULL)
				{
					ptr->id = 0;
				}
				printf("\n*************************** Cancel Reservation is Done Successfully ***************************\n");
				printf("********************** Thank You *********************************\n");
				printf("-------------------------------------------------------------------\n\n");
				break;
			}
			else
			{
				printf("Incorrect ID!, Please Try Again : ");
			}
		} // for while(1)
	}
	else
	{
		printf("-------------------------------------------------------------------\n");
		printf("No patients yet Reserved any Slots To Cancel!\n\n");
		printf("-------------------------------------------------------------------\n\n");
	}
}

/******************** Today_Reservation Function To Print The Day Reservation ********************/
void Today_Reservation()
{
	reservation *ptr = NULL;
	u8 counter = 1, flag = 0;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->id != 0)
		{
			printf("Reservation Slot Number %d is :-\t%s \t ID: %d \n", counter, ptr->time, ptr->id);
			counter++;
			flag = 1;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("No Reservation yet!\n\n");
	}
}
/******************** User Function To Display the Options available to the User  ********************/
void User()
{
	u8 choose, entered_ID, flag = 1;
	patient_node *Ptr = NULL;

	while (flag == 1)
	{
		printf("\nEnter 1 For Viewing Patient Record\nEnter 2 For Viewing today's Reservations\nEnter 3 For Main Minue\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			if (Head != NULL)
			{
				printf("Enter the patient ID : ");
				scanf("%d", &entered_ID);
				if (Check_ID(entered_ID))
				{
					Print_PatientRecord(entered_ID);
				}
				else
				{
					printf("Incorrect ID!\n\n");
				}
			}
			else
			{
				printf("\n-------------------------------------------------------------------");
				printf("\nNo patients yet ! \n");
				printf("\n-------------------------------------------------------------------\n\n");
				flag = 1;
			}
			break;

		case 2:
			printf("\n-------------------------------------------------------------------\n");
			Today_Reservation();
			printf("-------------------------------------------------------------------\n");
			break;

		case 3:
			Main_Minue();
			break;
		default:
			printf("Incorrect Choose!Try Again\n");
			flag = 1;
			break;

		} // for switch (choose)
	}	  // for while(flag == 1 )
}
