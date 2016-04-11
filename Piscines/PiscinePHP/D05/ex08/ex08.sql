SELECT nom, prenom, DATE(date_de_naissance) FROM fiche_personne WHERE DATE_FORMAT(date_de_naissance, "%Y") == 1989;
