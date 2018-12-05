# Lokaverkefni C++

## Markmið
Markmiðið er að búa til console/terminal forrit til að ná í og senda email. 

## Virkni
*Forritið mun byrja á því að biðja um upplýsingar um email sem á að nota, þær verða svo geymdar í skrá (encrypted og local) svo það þurfi ekki aftur. Svo fær notandi möguleika á að senda og skoða póst*
```
New email / Use previous
└─> Main-Menu: Inbox, Send Email, Send/Recieve, Settings, Quit
    Inbox
    └─> Sýnir (X) færslur í einu (merktar með ID) og Select (s), Next (->), Previous (<-) og Main Menu (q) skipanir.
        Select
        └─> Biður um ID (int) á færslu sem á að skoða nánar, opnar hana ef það er hægt annars reyndu aftur, "q" til að hætta.
    Send Email
    └─> Sýnir menu: Recipient, Subject, Body, Send, Main Menu, ekki er hægt að senda nema allir reitir séu fylltir.
        Recipient
        └─> Biður um gilt email (validatað með regex), eða "q" til að hætta.
        Subject
        └─> Biður um subject (má vera tómt), eða "q" til að hætta.
        Body
        └─> Skrifar body eins og venjulega, CTRL+D þegar þú ert búinn. Þá sérðu body'ið og getur haldið því, gert nýtt eða hætt við.
        Send
        └─> Sýnir Recipient, Subject og Body og býður uppá Send (Bara ef skilyrði eru uppfyllt) eða Back.
    Send/Recieve
    └─> Sýnir progress, eða bara tókst eða ekki.
    Settings
    └─> Inbox Page Count og Back. Mögulega fleiri ef okkur dettur eitthvað í hug
        Inbox Page Count
        └─> Tekur inn (int) frá 1-100 eða "q" til að hætta við.
    Quit
    └─> Kveður og lokar forritinu.
 ```
