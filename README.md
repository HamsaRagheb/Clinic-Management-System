# Clinic-Management-System
At the beginning of the system it asks the user to choose
between admin mode and user mode.

Admin Mode:

1)Password Entry:

  -Upon entering admin mode, the system prompts for a password.
 
  -The default password is 1234.
 
  -Users have 3 attempts to enter the correct password.
 
  -If the password is incorrect for 3 consecutive times, the system closes.

2)Add New Patient Record:

  -Admins can add new patient records.
 
  -Required information includes: name, age, gender, and a unique ID.
 
  -If the entered ID already exists, the system rejects the entry.

3)Edit Patient Record:

  -By entering a patient ID, the system checks if the ID exists.
 
  -If valid, the user can edit patient information.
 
  -Otherwise, an incorrect ID message is displayed.

4)Reserve a Slot with the Doctor:

  -Default available slots: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm.
 
  -Upon opening the reservation window, available slots are displayed.
 
  -Admins enter the patient ID and desired slot.
 
  -Reserved slots won’t appear again for subsequent reservations.

5)Cancel Reservation:

  -Admins can cancel a reservation by entering the patient ID.
 
  -The canceled reservation becomes available again in the slots window.

User Mode:

1)View Patient Record:

  -Users enter a patient ID to view basic patient information.
 
2)View Today’s Reservations:

  -The system displays all reservations for the day, with patient IDs attached to each slot.


