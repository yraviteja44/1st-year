#include <stdio.h>
#include <mysql.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	MYSQL *gun=mysql_init(NULL);
	
	if(gun==NULL){fprintf(stderr,"%s\n",mysql_error(gun));
	exit(1);
	} 
	if(mysql_real_connect(gun,"localhost","root","root",NULL,0,NULL,0)==NULL){fprintf(stderr,"%s\n",mysql_error(gun));
	}

	mysql_select_db(gun,"mom");
	char pname[999],patient_named[999],p,condition[999],sexf[2],delete_patdel[812],new_name[999],updated_sex[88],new_address[812],updated_new_number[812],updated_new_address[812],new_guardian[812],updated_new_guardian[812],croom[812];
	char ln[200],upi1[999],upi3[999],query[999],pass[200],card_name1[999],card_name2[999],card_name3[999],card_name4[999],name[200],f[812],sex[412],upi[999],upi2[999],bill_no_of_days[812],add[512],doc[512],input[512],search_patient[812],updated_new_age[812],new_sex[3],updated_new_gnumber[512],updated_new_doc[812],new_doc[812],new_condition[512],updated_new_condition[512];
	int i,j,payment_1,back,payment_3,card_number1,card_number2,card_number3,card_number4,card_exp2,card_exp3,card_cvv2,card_cvv3,card_cvv4,card_exp1,card_exp4,card_cvv1,view_patient_id,choice1,navi2,age,choiceroom,total_bill,choice2,recordchoice,patient_id,change_details,new_age,new_room,patdel,insurence_select;
	long long phno,phnof,pnum,pnumf,new_gnumber,new_number,new_numberf,new_gnumberf;
	int view_navi,payment_2,payment_4,navi1,navi3,navi4,main_navi,ret,room_days6,room_days7,total_bill4,amount_room_days8,food_charge6,bill_id,operation_fees,room_days,total_bill2,total_bill3,room_days1,room_days2,room_days3,room_days4,room_days5,amount_room_days,amount_room_days1,amount_room_days2,food_charge4,food_charge3,food_charge2,food_charge1;
	char bill[812],alldata[999],billroW[812],bill_no_of_days1[812],bill_no_of_days2[812],bill_name4[812],bill_name3[812],bill_name2[812],bill_name1[812],bill_name1_row[812],bill_no_of_daysg[812];
	char *room[]={"GENERAL WARD","2 SHARING ROOM WITH ATTACHED WASHROOM","SINGLE ROOM WITH ATTACHED WASHROOM","SINGLE AC ROOM WITH ATTACHED WASHROOM"};
	char *column_name[]={"PATIENT ID","NAME","AGE","SEX","PHONE NUMBER","ADDRESS","GAURDIAN","GAURDIAN PH NUM","CONDITION","ROOM","DOCTOR NAME AND DESIGNATON","ADMITTED DATE"};
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("|                                 <=======§ EVER GREEN SPRINGS  HOSPITAL §======>                            |\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	do{
	printf("enter your login id: \n");
	scanf("%s",&ln);
	printf("enter your password: ");
	//scanf("%s",&pass);
	while(1){
		p= _getch();
		if(p==13){
			pass[i]='\0';
			break;
		}
		else if(p==8 && i>0){printf("\b \b");
		i--;
		}
		else{
		 pass[i++]=p;
		printf("*");
	}
	}

	if(strcmp(ln,"rahul")==0 && strcmp(pass,"jai@9985")==0){
		pass[0]='\0';
	memset(pass,0,sizeof(pass));
	i=0;
		while(_kbhit()){_getch();
	}

	
		printf("\nSUCCESFULLY LOGGED IN..:)\n");
	    printf("             \n");
	    do{
		printf("\n++\n");
		printf("|SELECT YOUR DESIRED OPTION|\n");
		printf("++\n");
		printf("-----------------------------------\n");
		printf("|1.ADD A NEW PATIENT                |\n|2.MODIFY OR DELETE A PATIENT RECORD|\n|3.VIEW PATIENTS RECORDS            |\n|4.GENERATE BILL                    |\n|5.exit                             |\n");
		printf("+-----------------------------------+\n");
		printf("YOUR CHOICE: ");
		scanf("%d",&choice1);
		if(choice1==1){do{
		
			printf("\n\nENTER PATIENTS NAME: ");
			scanf(" %[^\n]",name);
			printf("ENTER AGE: ");
			scanf("%d",&age);			
			printf("ENTER SEX M or F: ");
			scanf("%s",&sex);
			do{	
			printf("ENTER PATIENTS PHONE NUMBER: ");
			scanf("%lld",&phnof);
			if(phnof>=1000000000 && phnof<=9999999999){
				phno=phnof;
			}
			else{phno=0;
			printf("\n INVALID PHONE NUMBER...\n");
			  }
		    }while(phno!=phnof);
			printf("ENTER PATIENTS ADDRESS: ");
			scanf(" %[^\n]",&add);
			printf("ENTER PATIENTS RELATIVE OR GAURDIAN OR PARENTS NAME: ");
			scanf(" %[^\n]",&pname);
			do{
			
			printf("ENTER PATIENTS RELATIVE OR GAURDIAN OR PARENTS PHONE NUMBER : ");
			scanf(" %lld",&pnumf);
			if(pnumf>=1000000000 && pnumf<=9999999999){
				pnum=pnumf; 
			}
			else{pnum=0;
			printf("\nINVALID NUMBER...\n");
			}
		     }while(pnum==0);
			printf("ENTER PATIENT'S CONDITION: ");
			scanf(" %[^\n]",&condition);
			do{
			
			printf("SELECT YOUR DESIRED  ROOM \n\n\n 0.GENERAL WARD-1200/- PER DAY\n 1. 2 SHARING ROOM WITH ATTACHED WASHROOM 4000/- PER DAY \n 2.SINGLE ROOM WITH ATTACHED WASHROOM \n 3.SINGLE AC ROOM WITH ATTCHED WASHROOM\n");
			printf("\n\nENTER YOUR CHOICE: ");
			scanf("%d",&choiceroom);
			if(choiceroom!=0 && choiceroom!=1 && choiceroom!=2 && choiceroom!=3){printf("\n\nINVALID OPTION...\n\n");
			}
		}while(choiceroom!=0 && choiceroom!=1 && choiceroom!=2 && choiceroom!=3);
			printf("\n\nPLEASE ENTER DOCTOR NAME AND DESIGNATION: ");
			scanf(" %[^\n]",&doc);
			snprintf(input,sizeof(input),"insert into hospital values(NULL,'%s',%d,'%s',%lld,'%s','%s',%lld,'%s','%s','%s',now());",name,age,sex,phno,add,pname,pnum,condition,room[choiceroom],doc);
			if(mysql_query(gun,input)){fprintf(stderr,"%s\n",mysql_error(gun));
			}
			else{printf("RECORD HAS BEEN ADDED..:)\n\n\n");
			}
			printf("\nDO YOU WANT TO ADD ANOTHER RECORD \n 1.YES     2.NO ");
			scanf("%d",&ret);
		}while(ret!=2);
		}
		else if(choice1==2){
			printf("++\n");
			printf("|1.CHANGE A PATIENTS RECORD| \n|2.DELETE A RECORD         | \n|3.exit                    |");
			printf("\n++");
			printf("\nYOUR CHOICE: ");
			scanf("%d",&choice2);
			if(choice2==1){
				do{
				
				printf("enter patients id you want to change: ");
				scanf("%d",&patient_id);
				printf("++\n");							
			    printf("|WHAT DO YOU WANT TO CHANGE IN THIS PATIENTS RECORD            |\n|1.NAME                                                        |\n|2.PATIENTS AGE                                                |\n|3.PATIENTS SEX                                                |\n|4.PATIENTS PHONE NUMBER                                       |\n|5.PATIENTS ADDRESS                                            |\n|6.PATIENTS RELATIVE OR GUARDIAN NAME OR PARENT NAME           |\n|7.PATIENTS RELATIVE OR GUARDIAN NAME OR PARENT NAME NUMBER    |\n|8.PATIENTS CONDITION                                          |\n|9.PATIENTS ROOM                                               |\n|10.DOCTOR NAME AND DESIGNATION                                |");
			    printf("\n++");
				printf("\nYOUR CHOICE: ");
				scanf("%d",&change_details);
				switch(change_details){
					case 1:
						printf("ENTER PATIENTS NEW NAME:");
						scanf(" %[^\n]",&new_name);
						snprintf(search_patient,sizeof(search_patient),"update hospital set name = '%s' where patient_id=%d;",new_name,patient_id);
						if(mysql_query(gun,search_patient)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("PATIENT'S NEW NAME HAS BEEN UPDATED...:)");
						//printf("DO YOU WANT TO CHANGE ANOTHER DDETAILS OF THIS PATIENT\n1.YES    2.NO\n");
						//scanf("%d",navi1);
						
						}
						break;
					case 2:
					    printf("ENTER PATIENTS NEW AGE: ");
						scanf("%d",&new_age);	
						snprintf(updated_new_age,sizeof(updated_new_age),"update hospital set age = %d where patient_id=%d;",new_age,patient_id);
						if(mysql_query(gun,updated_new_age)){
							fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{
							printf("NEW AGE HAS BEEN UPDATED..:)");
						}
						break;
					case 3:
					    printf("ENTER PATIENTS'S SEX M or F: ");
						scanf("%s",&new_sex);
						snprintf(updated_sex,sizeof(updated_sex),"update hospital set sex = '%s' where patient_id=%d;",new_sex,patient_id);
						if(mysql_query(gun,updated_sex)){
							fprintf(stderr,"%s\n",mysql_error(gun));
						}	
						else{printf("PATIENT'S SEX HAS BEEN UPDATED....:)");
						}
						break;
					case 4:
						do{
						
					    printf("ENTER PATIENT'S NEW NUMBER: ");
						scanf("%lld",&new_numberf);
						if(new_numberf>=1000000000 && new_numberf<=9999999999){
							new_number=new_numberf;
						}
						else{new_number=0;
						printf("INVALID NUMBER...\n");
						}
					    }while(new_number!=new_numberf);
						snprintf(updated_new_number,sizeof(updated_new_number),"update hospital set phno= %d where patient_id=%d",new_number,patient_id);
						if(mysql_query(gun,updated_new_number)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{
							printf("PATIENT'S NEW NUMBER HAS BEEN UPDATED...:)");
						}
						break; 
					case 5:
					    printf("ENTER PATIENT'S NEW ADDRESS: ");
						scanf(" %[^\n]",&new_address);
						snprintf(updated_new_address,sizeof(updated_new_address),"update hospital set address='%s' where patient_id=%d;",new_address,patient_id);
						if(mysql_query(gun,updated_new_address)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("PATIENT'S NEW ADDRESS HAS BEEN UPDATED...:)");
						}
						break;
					case 6:
						printf("ENTER PATIENTS NEW RELATIVE OR GUARDIAN NAME OR PARENT NAME: ");
						scanf(" %[^\n]",&new_guardian);
						snprintf(updated_new_guardian,sizeof(updated_new_guardian),"update hospital set gaurdian= '%s' where patient_id=%d;",new_guardian,patient_id);
						if(mysql_query(gun,updated_new_guardian)){
							fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else {
							printf("PATIENTS GUARDIANS DETAILS HAS BEEN UPDATED...:)");
						}
					    
						break;
					case 7:  do{
						
					
						printf("ENTER PATIENTS NEW RELATIVE OR GUARDIAN OR PARENT NUMBER: ");
						scanf("%lld",&new_gnumberf);
						if(new_gnumberf>=1000000000 && new_gnumberf<=9999999999){
							new_gnumber=new_gnumberf;
						}
						else{new_gnumber=0;
						printf("INVALID NUMBER...\n");
						}
					    }while(new_gnumber!=new_gnumberf);
						snprintf(updated_new_gnumber,sizeof(updated_new_gnumber),"update hospital set gaurdian_phno=%d where patient_id=%d;",new_gnumber,patient_id);
					    if(mysql_query(gun,updated_new_gnumber)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("PATIENTS NEW GUARDIAN NUMBER HAS BEEN UPDATED..:)");
						 }
					  
						break;
					case 8:
						printf("ENTER PATIENTS NEW CONDITION: ");
						scanf(" %[^\n]",&new_condition);
						snprintf(updated_new_condition,sizeof(updated_new_condition),"update hospital set status ='%s' where patient_id=%d;",new_condition,patient_id);
						if(mysql_query(gun,updated_new_condition)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("PATIENTS CONDITION HAS BEEN UPDATED....:)");
						}
					    break;
					case 9:do{
						
					
						printf("SELECT YOUR NEW DESIRED ROOM \n 0.GENERAL WARD-1200/- PER DAY\n 1. 2 SHARING ROOM WITH ATTACHED WASHROOM 4000/- PER DAY \n 2.SINGLE ROOM WITH ATTACHED WASHROOM \n 3.SINGLE AC ROOM WITH ATTCHED WASHROOM\n");
					    scanf("%d",&new_room);
					    if(new_room!=0 && new_room!=1 &&new_room!=2 &&new_room!=3){printf("\n\nINVALID OPTION...\n\n");
						}
					     }while(new_room!=0 && new_room!=1 && new_room!=2 && new_room!=3);
					    snprintf(croom,sizeof(croom),"update hospital set room = '%s' where patient_id=%d;",room[new_room],patient_id);
					    if(mysql_query(gun,croom)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("YOUR DESIRED ROOM HAS BEEN CHANGED....:)");
						}
						break;
					case 10:
					    printf("ENTER NEW DOCTOR NAME AND DESIGNATION: ");
					    scanf(" %[^\n]",&new_doc);
					    snprintf(updated_new_doc,sizeof(updated_new_doc),"update hospital set doctor_name_designation='%s' where patient_id=%d;",new_doc,patient_id);
					    if(mysql_query(gun,updated_new_doc)){fprintf(stderr,"%s\n",mysql_error(gun));
						}
						else{printf("PATIENTS DOCTOR'S DETAILS HAS BEEN UPDATED: ");
						}
					    break;
					default : printf("INVALID OPTION...");				
				}printf("\n DO YOU WANT TO CHANGE ANY OTHER PATIENTS DETAILS\n 1.YES   2.NO 3.MAIN MENU");
				scanf("%d",&navi1);
				if(navi1==3){main_navi=1;
				}
			}while(navi1!=2 && navi1!=3);
			}
			
			if(choice2==2){do{
			
				printf("ENTER PATIENT_ID THAT NEED TO BE DELETED: ");
				scanf("%d",&patdel);
				snprintf(delete_patdel,sizeof(delete_patdel),"delete from hospital where patient_id=%d;",patdel);
				if(mysql_query(gun,delete_patdel)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
				else{printf("PATIENTS RECORD HAS BEEN DELETED......:)");
				}
				printf("\nDO YOU WANT TO DELETE ANOTHER PATIENTS RECORD \n1.YES   2.NO");
				scanf("%d",&navi2);
				
			  }while(navi2!=2);
			}
			else if(choice2==3){exit(0);
			}
			else{printf("INVALID OPTION..");
			}
		}
		else if(choice1==3){
			mysql_select_db(gun,"mom");
			do{
			
			printf("\n\nSELECT YOUR DESIRED OPTION \n1.VIEW ALL PATIENTS RECORDS \n2.VIEW A SPECIFIC PATIENTS RECORD");
			printf("\nYOUR CHOICE: ");
			scanf("%d",&recordchoice);
			if(recordchoice==1){
				snprintf(query,sizeof(query),"select * from hospital ;");
				if(mysql_query(gun,query)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
				else{printf("QUERY EXECUTED SUCCESFULLY\n\n\n\n");
				
				}
				MYSQL_RES *rs=mysql_store_result(gun);
				if(rs==NULL){
					fprintf(stderr,"%s\n",mysql_error(gun));
				}
				MYSQL_ROW record;
				int i,j;
			
				while((record=mysql_fetch_row(rs))){
					for(j=0;j<12;j++){
						printf("%-12s",column_name[j]);
					}
					printf("\n");
					for(i=0;i<12;i++){
					     
						 
						 		 
					printf("%-12s|",record[i]?record[i]:"NULL");
					if((i+1)%12==0){
					
					printf("\n");
				}
				}
                  				
				}
				printf("GO BACK\n1.YES     2.NO exit: ");
				scanf("%d",&back);
				mysql_free_result(rs);
			//	mysql_close(gun);
				
				
			}
		
			/*	snprintf(alldata,sizeof(alldata),"select patient_id from hospital order by desc limit 1;");
				if(mysql_query(gun,alldata)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
				else{printf("query executed succesfully");
				}*/
				
			 
			else if(recordchoice==2){
				do{
				printf("ENTER PATIENT ID WHICH YOU WANT TO VIEW");
				scanf("%d",&view_patient_id);
				snprintf(patient_named,sizeof(patient_named),"select *from hospital where patient_id=%d;",view_patient_id);
				if(mysql_query(gun,patient_named)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
			//	else{printf("done");
			//	}
				MYSQL_RES *view=mysql_store_result(gun);
				
				MYSQL_ROW view_patient;
				while((view_patient=mysql_fetch_row(view))){
					for(j=0;j<12;j++){printf("%-12s",column_name[j]);
					}
					printf("\n");
					for(i=0;i<12;i++){
						
							printf("%-10s  ",view_patient[i]);
						
					}
				}
				printf("\n\n\n DO YOU WANT TO VIEW ANOTHER PATIENTS RECORD\n1.YES 2.NO EXIT 3.MAIN MENU");
				scanf("%d",&view_navi);
				if(view_navi==3){
					main_navi=1;
				}
				else if(view_navi==2){exit(0);
				}
			}while(view_navi==1);
			}
			}while(back==1);
		}
	
		else if(choice1==4){
			do{
			printf("ENTER PATIENT'S id: ");
			scanf("%d",&bill_id);
			printf("ENTER OPERATION FEES: ");
			scanf("%d",&operation_fees);
			snprintf(bill,sizeof(bill),"select room from hospital where patient_id=%d;",bill_id);
			if(mysql_query(gun,bill)){
				fprintf(stderr,"%s\n",mysql_error(gun));
			}
			else{
				//printf("query succesfull executed...");
			}
			MYSQL_RES *billres=mysql_store_result(gun);
			MYSQL_ROW billrow;
			while((billrow=mysql_fetch_row(billres))){
				//printf("\n%s\n",billrow[0]);
			
				
			if(strcmp(billrow[0],"GENERAL WARD")==0){
				 snprintf(bill_name1,sizeof(bill_name1),"select name from hospital where patient_id=%d",bill_id);
			  if(mysql_query(gun,bill_name1)){fprintf(stderr,"%s\n",mysql_error(gun));
			  }
			  MYSQL_RES *bill_name_1=mysql_store_result(gun);
			  MYSQL_ROW bill_name1_row;
			   while((bill_name1_row=mysql_fetch_row(bill_name_1))){
			  	printf("\nPATIENT NAME = %s\n",bill_name1_row[0]);
			  }	
			  	snprintf(bill_no_of_daysg,sizeof(bill_no_of_daysg),"select datediff(now(),admitted_date) as no_of_days_admitted from hospital where patient_id=%d;",bill_id);
				if(mysql_query(gun,bill_no_of_daysg)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
				MYSQL_RES *days3=mysql_store_result(gun);
				MYSQL_ROW days3_row;
			  	while((days3_row=mysql_fetch_row(days3))){
					//printf("\n%s\n",days_row[0]);
					room_days6=atoi(days3_row[0]);
					room_days7=room_days6+1;
					food_charge6=room_days7*700;
					amount_room_days8=room_days7*1000;
					total_bill4=amount_room_days8+operation_fees+food_charge6;
					printf("ROOM CHARGE PER DAY FOR GENERAL WARD = 1000 RS\nROOM CHARGE FOR %d DAYS = %d RS\nOPERATION FEES = %d RS\nFOOD CHARGER PER DAY = 700\nFOOD CHARGE FOR %d DAYS = %d RS\nTOTAL BILL= %d RS",room_days7,amount_room_days8,operation_fees,room_days7,food_charge6,total_bill4);
					do{
					
					printf("\nCHOOSE THE MODE OF PAYMENT\n1.CASH\n2.UPI PAYMENT\n3.CREDIT OR DEBIT CARD\nYOUR CHOICE: ");
					scanf("%d",&payment_4);
					if(payment_4==1){printf("\n\nPLEASE COLLECT %d RS FROM PATIENT\n\n\n ",total_bill4);
					}
					else if(payment_4==2){printf("ENTER YOUR UPI ID: \n");
					scanf(" %[^\n]",&upi3);
					printf("\n\nPLEASE COMPLETE PAYMENT IN YOUR UPI APP\n\n\n");
					}
						else if(payment_4==3){printf("ENTER YOUR CREDIT OR DEBIT CARD NUMBER: ");
				scanf("%d",&card_number4);
				printf("ENTER NAME  ON CARD: ");
				scanf(" %[^\n]",&card_name4);
				printf("ENTER EXPIRY DATE OF THE CARD: ");
				scanf(" %[^\n]",&card_exp4);
				printf("ENTER CVV: ");
				scanf("%d",&card_cvv4);
				printf("\n\nPAYMENT HAS BEEN SUCCESSFULLY COMPLETED..:)\n\n");
			}
					else{printf("INVALID OPTION....");
					}
			      }while(payment_4!=1 && payment_4!=2 && payment_4!=3);
				}
			//	total_bill=operation_fees+700+1000;
			//	printf("YOUR BILL IS %d \n",total_bill);
				mysql_free_result(billres);
			}
			
			  
			else if(strcmp(billrow[0],"2 SHARING ROOM WITH ATTACHED WASHROOM")==0){
			 snprintf(bill_name2,sizeof(bill_name2),"select name from hospital where patient_id=%d",bill_id);
			  if(mysql_query(gun,bill_name2)){fprintf(stderr,"%s\n",mysql_error(gun));
			  }
			  MYSQL_RES *bill_name_2=mysql_store_result(gun);
			  MYSQL_ROW bill_name2_row;
			  while((bill_name2_row=mysql_fetch_row(bill_name_2))){
			  	printf("\nPATIENT NAME = %s\n",bill_name2_row[0]);
			  }	
				
				snprintf(bill_no_of_days,sizeof(bill_no_of_days),"select datediff(now(),admitted_date) as no_of_days_admitted from hospital where patient_id=%d;",bill_id);
				if(mysql_query(gun,bill_no_of_days)){fprintf(stderr,"%s\n",mysql_error(gun));
				}
				MYSQL_RES *days=mysql_store_result(gun);
				MYSQL_ROW days_row;
				while((days_row=mysql_fetch_row(days))){
					//printf("\n%s\n",days_row[0]);
					room_days=atoi(days_row[0]);
					room_days1=room_days+1;
					food_charge2=room_days1*1000;
					amount_room_days=room_days1*4000;
					total_bill2=amount_room_days+operation_fees+food_charge2;
					printf("ROOM CHARGE PER DAY FOR 2 SHARING WITH ATTACHED WASHROOM = 4000 RS\nROOM CHARGE FOR %d DAYS = %d RS\nOPERATION FEES = %d RS\nFOOD CHARGER PER DAY = 1000\nFOOD CHARGE FOR %d DAYS = %d RS\nTOTAL BILL= %d RS",room_days1,amount_room_days,operation_fees,room_days1,food_charge2,total_bill2);
						do{
						
						printf("\nCHOOSE YOUR PAYMENT METHOD \n1.CASH\n2.UPI PAYMENT\n3.CREDIT OR DEBIT CARD\nYOUR CHOICE: ");
						scanf("%d",&payment_3);
						if(payment_3==1){printf("PLEASE COLLECT %d RS FROM PATIENT\n\n\n",total_bill2);
						}
						else if(payment_3==2){printf("ENTER YOUR UPI ID: \n");
						scanf(" %[^\n]",&upi2);
						printf("\n\nPLEASE COMPLETE PAYMENT IN UPI APP\n\n\n");
						}
							else if(payment_3==3){printf("ENTER YOUR CREDIT OR DEBIT CARD NUMBER: ");
				scanf("%d",&card_number3);
				printf("ENTER NAME  ON CARD: ");
				scanf(" %[^\n]",&card_name3);
				printf("ENTER EXPIRY DATE OF THE CARD: ");
				scanf(" %[^\n]",&card_exp3);
				printf("ENTER CVV: ");
				scanf("%d",&card_cvv3);
				printf("\n\nPAYMENT HAS BEEN SUCCESSFULLY COMPLETED..:)\n\n");
			}
						else{printf("INVALID PAYMENT METHOD...");
						}
					}while(payment_3!=1 && payment_3!=2 && payment_3!=3);
				}
				mysql_free_result(days);
			}
			else if(strcmp(billrow[0],"SINGLE ROOM WITH ATTACHED WASHROOM")==0){
			 snprintf(bill_name3,sizeof(bill_name3),"select name from hospital where patient_id=%d",bill_id);
			  if(mysql_query(gun,bill_name3)){fprintf(stderr,"%s\n",mysql_error(gun));
			  }
			  MYSQL_RES *bill_name_3=mysql_store_result(gun);
			  MYSQL_ROW bill_name3_row;
			  while((bill_name3_row=mysql_fetch_row(bill_name_3))){
			  	printf("\nPATIENT NAME = %s\n",bill_name3_row[0]);
			  }	
			
			snprintf(bill_no_of_days1,sizeof(bill_no_of_days1),"select datediff(now(),admitted_date) as no_of_days_admitted from hospital where patient_id=%d;",bill_id);
			if(mysql_query(gun,bill_no_of_days1)){fprintf(stderr,"%s\n",mysql_error(gun));
			}
			MYSQL_RES *days1=mysql_store_result(gun);
			MYSQL_ROW days_row1;
			while((days_row1=mysql_fetch_row(days1))){
				room_days2=atoi(days_row1[0]);
				room_days3=room_days2+1;
				amount_room_days1=room_days3*8000;
				food_charge3=room_days3*2000;
				total_bill3=amount_room_days1+operation_fees+food_charge3;
				printf("ROOM CHARGE PER DAY FOR SINGLE ROOM WITH ATTACHED WASHROOM = 8000\nROOM CHARGE FOR %d DAYS = %d RS\nOPERATION FEES = %d RS\nFOOD CHARGE PER DAY = 2000\nFOOD CHARGE FOR %d DAYS = %d RS\nTOTAL BILL= %d RS",room_days3,amount_room_days1,operation_fees,room_days3,food_charge3,total_bill3);
			    	do{
					
					printf("\nCHOOSE YOUR PAYMENT METHOD \n1.CASH\n2.UPI PAYMENT\n3.CREDIT OR DEBIT CARD\nYOUR CHOICE: ");
			    	scanf("%d",&payment_2);
			    	if(payment_2==1){printf("PLEASE COLLECT %d RS FROM PATIENT\n\n\n",total_bill3);
					}
					else if(payment_2==2){printf("ENTER YOUR UPI ID: \n");
					scanf(" %[^\n]",&upi1);
					printf("\n\nPLEASE COMPLETE PAYMENT IN YOUR UPI APP\n\n\n");
					}
						else if(payment_2==3){printf("ENTER YOUR CREDIT OR DEBIT CARD NUMBER: ");
				scanf("%d",&card_number2);
				printf("ENTER NAME  ON CARD: ");
				scanf(" %[^\n]",&card_name2);
				printf("ENTER EXPIRY DATE OF THE CARD: ");
				scanf(" %[^\n]",&card_exp2);
				printf("ENTER CVV: ");
				scanf("%d",&card_cvv2);
				printf("\n\nPAYMENT HAS BEEN SUCCESSFULLY COMPLETED..:)\n\n");
			}
					else{printf("INVALID PAYMENT OPTION....");
					}
				  }while(payment_2!=1 && payment_2!=2 && payment_2!=3);
				}
			   mysql_free_result(days1);
		      
		      }
		    else if(strcmp(billrow[0],"SINGLE AC ROOM WITH ATTACHED WASHROOM")==0){
				
			  
			  snprintf(bill_name4,sizeof(bill_name4),"select name from hospital where patient_id=%d",bill_id);
			  if(mysql_query(gun,bill_name4)){fprintf(stderr,"%s\n",mysql_error(gun));
			  }
			  MYSQL_RES *bill_name_4=mysql_store_result(gun);
			  MYSQL_ROW bill_name4_row;
			  while((bill_name4_row=mysql_fetch_row(bill_name_4))){
			  	printf("\n PATIENT NAME = %s\n",bill_name4_row[0]);
			  }
			
			snprintf(bill_no_of_days2,sizeof(bill_no_of_days2),"select datediff(now(),admitted_date) as no_of_days_admitted from hospital where patient_id=%d;",bill_id);
			if(mysql_query(gun,bill_no_of_days2)){fprintf(stderr,"%s\n",mysql_error(gun));
			}
			
			MYSQL_RES *days2=mysql_store_result(gun);
			MYSQL_ROW days_row2;
			while((days_row2=mysql_fetch_row(days2))){
				room_days4=atoi(days_row2[0]);
				room_days5=room_days4+1;
				amount_room_days2=room_days5*10000;
				food_charge4=room_days5*4000;
				total_bill3=amount_room_days2+operation_fees+food_charge4;
				
				printf("ROOM CHARGE PER DAY FOR SINGLE AC ROOM WITH ATTACHED WASHROOM = 10000 RS\nROOM CHARGE FOR %d DAYS = %d RS\nOPERATION FEES = %d RS\nFOOD CHARGE PER DAY = 4000 RS\nFOOD CHARGE FOR %d DAYS = %d RS\nTOTAL BILL= %d RS",room_days5,amount_room_days2,operation_fees,room_days5,food_charge4,total_bill3);
			    do{
				
				printf("\nCHOOSE YOUR PAYMENT METHOD \n1.CASH\n2.UPI PAYMENT\n3.CREDIT OR DEBIT CARD\nYOUR CHOICE: ");
			    scanf("%d",&payment_1);
			    if(payment_1==1){printf("PLEASE COLLECT %d RS FROM PATIENT\n\n\n",total_bill3);
				}
				else if(payment_1==2){printf("ENTER YOUR UPI ID: \n");
				scanf(" %[^\n]",&upi);
				printf("\n\nPLEASE COMPLETE PAYMENT IN YOUR UPI APP\n\n\n");
				}
				else if(payment_1==3){printf("ENTER YOUR CREDIT OR DEBIT CARD NUMBER: ");
				scanf("%d",&card_number1);
				printf("ENTER NAME  ON CARD: ");
				scanf(" %[^\n]",&card_name1);
				printf("ENTER EXPIRY DATE OF THE CARD: ");
				scanf(" %[^\n]",&card_exp1);
				printf("ENTER CVV: ");
				scanf("%d",&card_cvv1);
				printf("\n\nPAYMENT HAS BEEN SUCCESSFULLY COMPLETED..:)\n\n");
				}
				else{printf("INVALID PAYMENT METHOD...");
				}
			    }while(payment_1!=1 && payment_1!=2 && payment_1!=3);
				}
			    
			    
			   mysql_free_result(days2);
		    }   
			}	
			 printf("\nDO YOU WANT TO GENERATE ANOTHER BILL\n1.YES 2.NO EXIT 3.MAIN MENU\n");	
			scanf("%d",&navi4);	
			if(navi4==3){main_navi=1;
			}
			
	    } while(navi4==1);
	      }
		else if(choice1==5){exit(0);
		}
		else{printf("INVALID OPTION..");
		}
       
      	
	 }while(main_navi==1);
     }
	else{printf("\n\nINVAVILD ID OR PASSWORD...\n\n");
		memset(pass,0,sizeof(pass));
	i=0;
	while(_kbhit()){_getch();
	}
	
	}
	printf("\n\n\nDO YOU WANT TO login AGAIN\n1.YES   2.NO\n\n");
	scanf("%d",&navi3); 
  }while(navi3!=2);

	return 0;
	}