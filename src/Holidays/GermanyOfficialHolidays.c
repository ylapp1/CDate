/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Provides all official holidays in germany.
 * Does not differentiate between federal states (e.g. Hessen, Bayern, etc.)
 *
 * This list was used to determine all official holidays: https://www.ferienwiki.de/feiertage/2019/de
 */
public class GermanyOfficialHolidays: OfficialHolidays
{
  /**
   * Returns the offical holiday name for a specified date.
   * Will return an empty string if there is no official holiday on that date.
   *
   * @param _date The date to fetch the official holiday name for
   *
   * @return string The official holiday name
   */
  public override string getDayOfficialHolidayName(CDate _date)
  {
    // Static days
    if (isNewYearsDay(_date)) return "Neujahrstag";
    else if (isEpiphany(_date)) return "Heilige drei Könige";
    else if (isInternationalWomenDay(_date)) return "Internationaler Frauentag";
    else if (isDayOfWork(_date)) return "Tag der Arbeit";
    else if (isPeaceOfAugsburgDay(_date)) return "Augsburger Friedensfest";
    else if (isAssumptionOfMaryDay(_date)) return "Mariä Himmelfahrt";
    else if (isGermanUnificationDay(_date)) return "Tag der Deutschen Einheit";
    else if (isReformationDay(_date)) return "Reformationstag";
    else if (isAllHallowsDay(_date)) return "Allerheiligen";
    else if (isFirstChristmasDay(_date)) return "Erster Weihnachtsfeiertag";
    else if (isSecondChristmasDay(_date)) return "Zweiter Weihnachtsfeiertag";
    else if (isSylvester(_date)) return "Sylvester";


    // Days that depend on the movable date of Easter
    CDate easterDate = calculateEasterDate(_date.yearNumber());

    // @see https://de.wikipedia.org/wiki/Gesetzliche_Feiertage_in_Deutschland#Bewegliche_Feiertage
    if (isEaster(_date, easterDate)) return "Ostersonntag";
    else if (isEasterMonday(_date, easterDate)) return "Ostermontag";
    else if (isGoodFriday(_date, easterDate)) return "Karfreitag";
    else if (isAscensionOfChristDay(_date, easterDate)) return "Christi Himmelfahrt";
    else if (isWhitsunday(_date, easterDate)) return "Pfingstsonntag";
    else if (isWhitmonday(_date, easterDate)) return "Pfingstmontag";
    else if (isCorpusChristiDay(_date, easterDate)) return "Fronleichnam";


    // Other variable holidays
    else if (isDayOfRepentance(_date)) return "Buß- und Bettag";

    else return "";
  }


  /**
   * Returns whether a specified date is new years day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is new years day, false otherwise
   */
  public bool isNewYearsDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Neujahr
    return (_date.dayNumber() == 1 && _date.monthNumber() == 1);
  }

  /**
   * Returns whether a specified date is epiphany day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is epiphany day, false otherwise
   */
  public bool isEpiphany(CDate _date)
  { // https://de.wikipedia.org/wiki/Heilige_Drei_K%C3%B6nige
    return (_date.dayNumber() == 6 && _date.monthNumber() == 1);
  }

  /**
   * Returns whether a specified date is international women day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is international women day, false otherwise
   */
  public bool isInternationalWomenDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Internationaler_Frauentag
    return (_date.dayNumber() == 8 && _date.monthNumber() == 3);
  }

  /**
   * Returns whether a specified date is day of work.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is day of work, false otherwise
   */
  public bool isDayOfWork(CDate _date)
  { // https://de.wikipedia.org/wiki/Erster_Mai
    return (_date.dayNumber() == 1 && _date.monthNumber() == 5);
  }

  /**
   * Returns whether a specified date is peace of augsburg day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is peace of augsburg day, false otherwise
   */
  public bool isPeaceOfAugsburgDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Augsburger_Hohes_Friedensfest
    return (_date.dayNumber() == 8 && _date.monthNumber() == 8 && _date.yearNumber() >= 1650);
  }

  /**
   * Returns whether a specified date is assumption of mary day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is assumption of mary day, false otherwise
   */
  public bool isAssumptionOfMaryDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Mari%C3%A4_Aufnahme_in_den_Himmel
    return (_date.dayNumber() == 15 && _date.monthNumber() == 8);
  }

  /**
   * Returns whether a specified date is german unification day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is german unification day, false otherwise
   */
  public bool isGermanUnificationDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Tag_der_Deutschen_Einheit
    return (_date.dayNumber() == 3 && _date.monthNumber() == 10);
  }

  /**
   * Returns whether a specified date is reformation day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is reformation day, false otherwise
   */
  public bool isReformationDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Reformationstag
    return (_date.dayNumber() == 31 && _date.monthNumber() == 10);
  }

  /**
   * Returns whether a specified date is all hallows day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is all hallows day, false otherwise
   */
  public bool isAllHallowsDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Allerheiligen
    return (_date.dayNumber() == 1 && _date.monthNumber() == 11);
  }

  /**
   * Returns whether a specified date is first christmas day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is first christmas day, false otherwise
   */
  public bool isFirstChristmasDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Weihnachten#Feiertagsregelungen
    return (_date.dayNumber() == 25 && _date.monthNumber() == 12);
  }

  /**
   * Returns whether a specified date is second christmas day.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is second christmas day, false otherwise
   */
  public bool isSecondChristmasDay(CDate _date)
  { // https://de.wikipedia.org/wiki/Weihnachten#Feiertagsregelungen
    return (_date.dayNumber() == 26 && _date.monthNumber() == 12);
  }

  /**
   * Returns whether a specified date is sylvester.
   *
   * @param _date The date to check
   *
   * @return bool True if the date is sylvester, false otherwise
   */
  public bool isSylvester(CDate _date)
  { // https://de.wikipedia.org/wiki/Silvester
    return (_date.dayNumber() == 31 && _date.monthNumber() == 12);
  }


  /**
   * Returns whether a specified date is easter sunday.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is easter sunday, false otherwise
   */
  public bool isEaster(CDate _date, CDate _easterDate)
  {
    return (_date.compareTo(_easterDate) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is easter monday.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is easter monday, false otherwise
   */
  public bool isEasterMonday(CDate _date, CDate _easterDate)
  {
    CDate easterMonday = new CDate(_easterDate);
    easterMonday.addDays(1);

    return (_date.compareTo(easterMonday) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is good friday.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is good friday, false otherwise
   */
  public bool isGoodFriday(CDate _date, CDate _easterDate)
  {
    CDate goodFriday = new CDate(_easterDate);
    goodFriday.addDays(-2);

    return (_date.compareTo(goodFriday) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is ascension of christ day.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is ascension of christ day, false otherwise
   */
  public bool isAscensionOfChristDay(CDate _date, CDate _easterDate)
  {
    CDate ascensionOfChristDay = new CDate(_easterDate);
    ascensionOfChristDay.addDays(39);

    return (_date.compareTo(ascensionOfChristDay) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is whit sunday.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is whit sunday, false otherwise
   */
  public bool isWhitsunday(CDate _date, CDate _easterDate)
  {
    CDate whitsunday = new CDate(_easterDate);
    whitsunday.addDays(49);

    return (_date.compareTo(whitsunday) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is whit monday.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is whit monday, false otherwise
   */
  public bool isWhitmonday(CDate _date, CDate _easterDate)
  {
    CDate whitmonday = new CDate(_easterDate);
    whitmonday.addDays(50);

    return (_date.compareTo(whitmonday) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }

  /**
   * Returns whether a specified date is corpus christi day.
   *
   * @param _date The date to check
   * @param _easterDate The easter date for the date's year
   *
   * @return bool True if the date is corpus christi day, false otherwise
   */
  public bool isCorpusChristiDay(CDate _date, CDate _easterDate)
  {
    CDate corpusChristiDay = new CDate(_easterDate);
    corpusChristiDay.addDays(60);

    return (_date.compareTo(corpusChristiDay) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }


  /**
   * Returns the date of Easter for a specified year.
   * This was copied from https://de.wikibooks.org/wiki/Algorithmensammlung:_Kalender:_Feiertage.
   *
   * @param _year The year to calculate the Easter date for
   *
   * @return CDate The date of easter
   */
  private CDate calculateEasterDate(int _year)
  {
    int x = _year;		// das Jahr
    int k;			// die Säkularzahl
    int m;			// die säkulare Mondschaltung
    int s;			// die säkulare Sonnenschaltung
    int a;			// der Mondparameter
    int d;			// der Keim für den ersten Vollmond im Frühling
    int r;			// die kalendarische Korrekturgröße
    int og;			// die Ostergrenze
    int sz;			// der ersten Sonntag im März
    int oe;			// die Entfernung des Ostersonntags von der Ostergrenze
    int os;			// das Datum des Ostersonntags als Märzdatum (32.März = 1.April)
    int OsterTag;
    int OsterMonat;

    k = x / 100;
    m = 15 + (3 * k + 3) / 4 - (8 * k + 13) / 25;
    s = 2 - (3 * k + 3) / 4;
    a = x % 19;
    d = (19 * a + m) % 30;
    r = (d + a / 11) / 29;
    og = 21 + d - r;
    sz = 7 - (x + x / 4 + s) % 7;
    oe = 7 - (og - sz) % 7;
    os = og + oe;

    OsterMonat = 2 + (int)(os + 30) / 31;
    OsterTag = os - 31 * ((int)OsterMonat / 4);

    return new CDate(OsterTag, OsterMonat, _year);
  }


  /**
   * Returns whether a specified date is day of repentance.
   * This method is based on the logic of https://de.wikibooks.org/wiki/Algorithmensammlung:_Kalender:_Feiertage
   *
   * @param _date The date to check
   *
   * @return bool True if the date is day of repentance, false otherwise
   */
  public bool isDayOfRepentance(CDate _date)
  {
    // It's always a Wednesday between 16. and 22. November
    CDate dayOfRepentance = new CDate(22, 11, _date.yearNumber());


    // dayOfWeek returns 0-6 as week days, this algorithm uses 1 - 7 as week days
    int dayNumber = dayOfRepentance.getDayOfWeek() + 1;

    // Ensure that the day number is bigger than 3 (= Wednesday)
    if (dayNumber < 3) dayNumber += 7;

    // Jump to the last wednesday by subtracting (dayNumber - <WednesDay day number>) from 22. November
    dayOfRepentance.addDays(-1 * (dayNumber - 3));

    return (_date.compareTo(dayOfRepentance) == CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE);
  }
}
