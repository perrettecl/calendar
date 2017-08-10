 SELECT Event.title as nazev 
 FROM Event, person, eventInvolvedPerson 
 WHERE Event.idEvent = eventInvolvedPerson.idEvent
	AND eventInvolvedPerson.idPerson = person.idPerson
	AND person.name = "Jarmila"