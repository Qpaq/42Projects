INSERT INTO ft_table (nom, date_de_creation) VALUES `SELECT nom, date_naissance, LEN(nom) AS len_nom FROM fiche_personne WHERE ('a' IN nom) AND len_nom < 9 ORDER BY nom LIMIT 10`;
