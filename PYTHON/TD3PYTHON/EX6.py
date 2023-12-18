def conju(verbe):
    perso = ["Je", "Tu", "Il", "Nous", "Vous", "Ils"]
    termi = ["e", "es", "e", "ons", "ez", "ent"]
    verbe = verbe[:-2]
    for i in range(6):
        print(perso[i], verbe + termi[i], "\n")
verb = input("INput\n")
conju(verb)