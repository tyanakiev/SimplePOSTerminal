### Simple POS Terminal program

Part of my C++ course at UWGB.

> Check bottom of the page for a disclaimer.

## Home menu:

The POS system will have two different sets of menus. One menu is for the customers who come to the store to buy products. The other is for the administrator who runs the store. Imagine that the store runs by the administrator who can add new products and is interested to see report at his/her discretion. Therefore, you need to implement the initial menu as follows:
```
1.Customer
2.Admin
```
If option 1 is selected, your program will return the previous three menus (Customer menu) as follows:
```
1.Sale
2.Pay
3.Exit
```
## Customer Menu:
Option 1 = Sale: Sale mode will enable the following categories(category menu)
```
1.Bakery
2.Fruits
3.Grocery
4.Vegetables
```
For each category, the following products will be listed. Thus, if the user selects option 1 from the category menu, all the bread items will be displayed along with their unit price, similar to what you displayed in lab assignment 3.
![image](https://user-images.githubusercontent.com/5628399/110260744-0f530e00-7f73-11eb-9b30-2bc0e3fc7154.png)

Make sure you provide an exit option which will take back to the category menu to select any other category. In the category menu, you need to provide an exit option as well to take back the user to the customer menu. All these need to be in sale mode and you need to avoid taking back the user to the customer or main menu. The user can stay in thesale mode and select products to buy at his/her wish. Every time the user selects a product, the sale subtotal needs to be updated. Remember this is accumulated total of the sale. Optionally you can display the product-wise subtotal. For example, if a customer selects 2 Pc of watermelon then the total price will for this product is 4.02. The sale subtotal is the addition of 4.02 with the accumulated sale total of all the products the user has bought so 
far. Upon exiting the sale mode, your program should display the total amount as a reminder to the user that he/she has a sale overdue for payment.The pay option will work similar to what you implemented as part of assignment 3. The only option is that now customer can factor the total in multiple payments. For example, if the total sale is $25 and the user typed $15, your program will show the remaining balance and ask the user to pay the rest. If the customer pays the full then the sale total will be reset to 0. Remember, once the sale is paid in full the sale mode will initiate. This means that if a user selects the pay option again after paying the full amount, then it will prompt the user that “you have no sale overdue”.

## Admin Menu:

In the admin menu, you need to implement the following menu items:
```
1.Displaytotal salesvolumeby category
2.Displayname and units of highest sold itemin each category
3.Display name and sales volume for highest sold itemin each category
4.Displayname and units of lowest sold item in each category
5..Display name and sales volume for lowest sold item in each category
```
Upon exiting the admin menu, the program should go back to the home menu.You need to consider the user-friendly navigation for the user. Remember that adding multiple items may take the user to the bottom of the screen and he/she may need to scroll back to the initial menu items displayed in the beginning. Therefore, allow user to view the exit option always. If the user wants to go back to the sale mode even though he/she selected the pay option from the customer menu, you program needs to be flexible to do so. Further sale item may be added upon the user’s discretion. Don’t let the user to type the product name. Imagine the user who came to buy products is none but you. So provide flexibility and user friendly navigation as if you were buying through the POS system.You can use vectors/arrays to store your information, however design smartly so that it can accommodate future changes.







### Disclaimer

This disclaimer ("Disclaimer") sets forth the general guidelines, disclosures, and terms of your use of the github.com/tyanakiev/SimplePOSTerminal/ website ("Website"), "SimplePOSTerminal" mobile application ("Mobile Application") and any of their related products and services (collectively, "Services"). This Disclaimer is a legally binding agreement between you ("User", "you" or "your") and this Website operator and Mobile Application developer ("Operator", "we", "us" or "our"). By accessing and using the Services, you acknowledge that you have read, understood, and agree to be bound by the terms of this Disclaimer. If you are entering into this Disclaimer on behalf of a business or other legal entity, you represent that you have the authority to bind such entity to this Disclaimer, in which case the terms "User", "you" or "your" shall refer to such entity. If you do not have such authority, or if you do not agree with the terms of this Disclaimer, you must not accept this Disclaimer and may not access and use the Services. You acknowledge that this Disclaimer is a contract between you and the Operator, even though it is electronic and is not physically signed by you, and it governs your use of the Services. This disclaimer was created with the help of the disclaimer generator.

## Representation

Any views or opinions represented on the Services are personal and belong solely to the Operator and do not represent those of people, institutions or organizations that the Operator may or may not be associated with in professional or personal capacity unless explicitly stated. Any views or opinions are not intended to malign any religion, ethnic group, club, organization, company, or individual.

## Content and postings

You may print or copy any part of the Services for your personal or non-commercial use.

## Indemnification and warranties

While we have made every attempt to ensure that the information contained on the Services is correct, the Operator is not responsible for any errors or omissions, or for the results obtained from the use of this information. All information on the Services is provided "as is", with no guarantee of completeness, accuracy, timeliness or of the results obtained from the use of this information, and without warranty of any kind, express or implied. In no event will the Operator be liable to you or anyone else for any decision made or action taken in reliance on the information on the Services, or for any consequential, special or similar damages, even if advised of the possibility of such damages. Information contained on the Services are subject to change at any time and without warning.

## Changes and amendments

We reserve the right to modify this Disclaimer or its terms relating to the Services at any time, effective upon posting of an updated version of this Disclaimer on the Services. When we do, we will revise the updated date at the bottom of this page. Continued use of the Services after any such changes shall constitute your consent to such changes.

## Acceptance of this disclaimer

You acknowledge that you have read this Disclaimer and agree to all its terms and conditions. By accessing and using the Services you agree to be bound by this Disclaimer. If you do not agree to abide by the terms of this Disclaimer, you are not authorized to access or use the Services.

## Contacting us

If you have any questions about this Disclaimer, please contact us.

This document was last updated on March 7, 2021
