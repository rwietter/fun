package binary;

import java.util.Random;

public class Gen {
  private String[] names = { "Culpepper", "Coughlin", "Brinson", "Boudreau", "Barkley", "Bales", "Stepp", "Holm", "Tan",
      "Schilling", "Morrell", "Kahn", "Heaton", "Gamez", "Douglass", "Causey", "Brothers", "Turpin", "Shanks",
      "Schrader", "Meek", "Isom", "Hardison", "Carranza", "Yanez", "Way", "Scroggins", "Schofield", "Runyon",
      "Ratcliff", "Murrell", "Moeller", "Irby", "Currier", "Butterfield", "Yee", "Ralston", "Pullen", "Pinson", "Estep",
      "East", "Carbone", "Lance", "Hawks", "Ellington", "Casillas", "Spurlock", "Sikes", "Motley", "Mccartney",
      "Kruger", "Isbell", "Houle", "Francisco", "Burk", "Bone", "Tomlin", "Shelby", "Quigley", "Neumann", "Lovelace",
      "Fennell", "Colby", "Cheatham", "Bustamante", "Skidmore", "Hidalgo", "Forman", "Culp", "Bowens", "Betancourt",
      "Aquino", "Robb", "Rea", "Milner", "Martel", "Gresham", "Wiles", "Ricketts", "Gavin", "Dowd", "Collazo", "Bostic",
      "Blakely", "Sherrod", "Power", "Kenyon", "Gandy", "Ebert", "Deloach", "Cary", "Bull", "Allard", "Sauer", "Robins",
      "Olivares", "Gillette", "Chestnut", "Bourque", "Paine", "Lyman", "Hite", "Hauser", "Devore", "Crawley", "Chapa",
      "Vu", "Tobias", "Talbert", "Poindexter", "Millard", "Meador", "Mcduffie", "Mattox", "Kraus", "Harkins", "Choate",
      "Bess", "Wren", "Sledge", "Sanborn", "Outlaw", "Kinder", "Geary", "Cornwell", "Barclay", "Adam", "Abney",
      "Seward", "Rhoads", "Howland", "Fortier", "Easter", "Benner", "Vines", "Tubbs", "Troutman", "Rapp", "Noe",
      "Mccurdy", "Harder", "Deluca", "Westmoreland", "South", "Havens", "Guajardo", "Ely", "Clary", "Seal", "Meehan",
      "Herzog", "Guillen", "Ashcraft", "Waugh", "Renner", "Milam", "Jung", "Elrod", "Churchill", "Buford", "Breaux",
      "Bolin", "Asher", "Windham", "Tirado", "Pemberton", "Nolen", "Noland", "Knott", "Emmons", "Cornish",
      "Christenson", "Brownlee", "Barbee", "Waldrop", "Pitt", "Olvera", "Lombardi", "Gruber", "Gaffney", "Eggleston",
      "Banda", "Archuleta", "Still", "Slone", "Prewitt", "Pfeiffer", "Nettles", "Mena", "Mcadams", "Henning",
      "Gardiner", "Cromwell", "Chisholm", "Burleson", "Box", "Vest", "Oglesby", "Mccarter", "Malcolm", "Lumpkin",
      "Larue", "Grey", "Wofford", "Vanhorn", "Thorn", "Teel", "Swafford", "Stclair", "Stanfield", "Ocampo", "Herrmann",
      "Hannon", "Arsenault", "Roush", "Mcalister", "Hiatt", "Gunderson", "Forsythe", "Duggan", "Delvalle", "Cintron",
      "Guiness", "Wahlberg", "Chase", "Davis", "Lollobrigida", "Nicholson", "Mostel", "Johansson", "Swank", "Gable",
      "Cage", "Berry", "Wood", "Bergen", "Olivier", "Costner", "Voight", "Torn", "Fawcett", "Tracy", "Paltrow", "Marx",
      "Kilmer", "Streep", "Bloom", "Crawford", "Mcqueen", "Hoffman", "Wayne", "Peck", "Sobieski", "Hackman", "Peck",
      "Olivier", "Dean", "Dukakis", "Bolger", "Mckellen", "Brody", "Cage", "Degeneres", "Miranda", "Jovovich",
      "Stallone", "Kilmer", "Goldberg", "Barrymore", "Day-Lewis", "Cronyn", "Hopkins", "Phoenix", "Hunt", "Temple",
      "Pinkett", "Kilmer", "Harris", "Cruise", "Akroyd", "Tautou", "Berry", "Neeson", "Neeson", "Wray", "Johansson",
      "Hudson", "Tandy", "Bailey", "Winslet", "Paltrow", "Mcconaughey", "Grant", "Williams", "Penn", "Keitel", "Posey",
      "Astaire", "Mcconaughey", "Sinatra", "Hoffman", "Cruz", "Damon", "Jolie", "Willis", "Pitt", "Zellweger",
      "Chaplin", "Peck", "Pesci", "Dench", "Guiness", "Berry", "Akroyd", "Presley", "Torn", "Wahlberg", "Willis",
      "Hawke", "Bridges", "Mostel", "Depp", "Davis", "Torn", "Leigh", "Cronyn", "Crowe", "Dunst", "Degeneres", "Nolte",
      "Dern", "Davis", "Zellweger", "Bacall", "Hopkins", "Mcdormand", "Bale", "Streep", "Tracy", "Allen", "Jackman" };

  Random random = new Random();

  public String getRandomName() {
    return names[random.nextInt(names.length)];
  }

  public int getRandomAge() {
    return random.nextInt(130);
  }
}
