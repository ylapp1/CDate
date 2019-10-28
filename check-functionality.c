/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

using System;

/**
 * A program that checks that the CDate class works as expected.
 */
public class Program
{
  /**
   * Entry point of the program.
   */
  public static void Main()
  {
    Console.Write("Checking creation of CDate's ... ");
    checkCreation();
		Console.WriteLine("DONE");

    Console.Write("Checking CDate::compareTo() ... ");
    checkComparison();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::addDays() ... ");
    checkAddDays();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::diffNormal() ... ");
    checkDiffNormal();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::diff360() ... ");
    checkDiff360();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::getDayOfWeek() ... ");
    checkGetDayOfWeek();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::isOfficialHoliday() ... ");
    checkIsOfficialHoliday();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::toFormattedString() ... ");
    checkToFormattedString();
    Console.WriteLine("DONE");

    Console.Write("Checking CDate::toJulianDate() ... ");
    checkToJulianDate();
    Console.WriteLine("DONE");

    Console.WriteLine("SUCCESS\n");
	}


  /**
   * Asserts that a string equals another string.
   * If the strings are not equal an error will be printed and the program will be exited with a non zero code.
   *
   * @param _stringA The first string
   * @param _stringB The second string
   * @param _message The message that will be inserted into the error message if the strings are not equal
   */
  private static void assertStringEquals(string _stringA, string _stringB, string _message)
  {
    if (!String.Equals(_stringA, _stringB))
    {
        Console.WriteLine(String.Concat(_message, ": Expected \"", _stringA, "\", Got \"", _stringB, "\""));
        Environment.Exit(1);
    }
  }

  /**
   * Asserts that an integer equals another integer.
   * If the integers are not equal an error will be printed and the program will be exited with a non zero code.
   *
   * @param _intA The first integer
   * @param _intB The second integer
   * @param _message The message that will be inserted into the error message if the integers are not equal
   */
  private static void assertIntEquals(int _intA, int _intB, string _message)
  {
    if (_intA != _intB)
    {
        Console.WriteLine(String.Concat(_message, ": Expected \"", _intA, "\", Got \"", _intB, "\""));
        Environment.Exit(1);
    }
  }

  /**
   * Asserts that a double equals another double.
   * If the doubles are not equal an error will be printed and the program will be exited with a non zero code.
   *
   * @param _doubleA The first double
   * @param _doubleB The second double
   * @param _message The message that will be inserted into the error message if the doubles are not equal
   */
  private static void assertDoubleEquals(double _doubleA, double _doubleB, string _message)
  {
    if (_doubleA != _doubleB)
      {
        Console.WriteLine(String.Concat(_message, ": Expected \"", _doubleA, "\", Got \"", _doubleB, "\""));
        Environment.Exit(1);
      }
  }

  /**
   * Asserts that a boolean equals another boolean.
   * If the booleans are not equal an error will be printed and the program will be exited with a non zero code.
   *
   * @param _boolA The first boolean
   * @param _boolB The second boolean
   * @param _message The message that will be inserted into the error message if the booleans are not equal
   */
  private static void assertBoolEquals(bool _boolA, bool _boolB, string _message)
  {
    if (_boolA != _boolB)
    {
        Console.WriteLine(String.Concat(_message, ": Expected \"", _boolA, "\", Got \"", _boolB, "\""));
        Environment.Exit(1);
    }
  }


  /**
   * Checks that the CDate constructor works as expected.
   */
  private static void checkCreation()
  {
    CDate exampleDate;

    // Check if the created Dates generate the expected string
    exampleDate = new CDate(26, 2, 2017);
    assertStringEquals("26.02.2017", exampleDate.toString(), "CDate creation A");

    exampleDate = new CDate(24, 8, 2019);
    assertStringEquals("24.08.2019", exampleDate.toString(), "CDate creation B");

    exampleDate = new CDate(12, 12, 2014);
    assertStringEquals("12.12.2014", exampleDate.toString(), "CDate creation C");
  }

  /**
   * Checks that the "compareTo" method works as expected.
   */
  private static void checkComparison()
  {
    CDate dateA, dateB;

    // Compare dates with different day, month and year
    dateA = new CDate(26, 2, 2017);
    dateB = new CDate(24, 8, 2019);
    assertIntEquals(dateA.compareTo(dateB), CDate.COMPARESTATUS_LOWER_THAN_COMPARISON_DATE, "Simple date comparison (Everything different) A");
    assertIntEquals(dateB.compareTo(dateA), CDate.COMPARESTATUS_HIGHER_THAN_COMPARISON_DATE, "Simple date comparison (Everythinig different) B");

    // Same day
    dateA = new CDate(24, 7, 2013);
    dateB = new CDate(24, 11, 2019);
    assertIntEquals(dateA.compareTo(dateB), CDate.COMPARESTATUS_LOWER_THAN_COMPARISON_DATE, "Simple date comparison (Same day) A");
    assertIntEquals(dateB.compareTo(dateA), CDate.COMPARESTATUS_HIGHER_THAN_COMPARISON_DATE, "Simple date comparison (Same day) B");

    // Same day and same month
    dateA = new CDate(24, 7, 2011);
    dateB = new CDate(24, 7, 2015);
    assertIntEquals(dateA.compareTo(dateB), CDate.COMPARESTATUS_LOWER_THAN_COMPARISON_DATE, "Simple date comparison (Same day and month) A");
    assertIntEquals(dateB.compareTo(dateA), CDate.COMPARESTATUS_HIGHER_THAN_COMPARISON_DATE, "Simple date comparison (Same day and month) B");

    // Same day, same month and same year but two different objects
    dateA = new CDate(24, 7, 2011);
    dateB = new CDate(24, 7, 2011);
    assertIntEquals(dateA.compareTo(dateB), CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE, "Simple date comparison (Same data, but different objects) A");
    assertIntEquals(dateB.compareTo(dateA), CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE, "Simple date comparison (Same data, but different objects) A");

    // Compare CDate to itself
    dateA = new CDate(25, 7, 2003);
    assertIntEquals(dateA.compareTo(dateA), CDate.COMPARESTATUS_EQUAL_TO_COMPARISON_DATE, "Simple date comparison (Same data, same object)");
  }

  /**
   * Checks that the "addDays" method works as expected.
   */
  private static void checkAddDays()
  {
    CDate date = new CDate(26, 2, 2017);

		date.addDays(10);
    assertStringEquals("08.03.2017", date.toString(), "26.02.2017 + 10 days is 08.03.2017");

    date = new CDate(12, 4, 2012);
    date.addDays(8);
    assertStringEquals("20.04.2012", date.toString(), "12.04.2012 + 8 days is 20.04.2012");
  }

  /**
   * Checks that the "diffNormal" method works as expected.
   */
  private static void checkDiffNormal()
  {
    CDateDiff diff;
    CDate dateA, dateB;

    dateA = new CDate(3, 1, 2018);
    dateB = new CDate(6, 2, 2019);

    diff = dateA.diffNormal(dateB);
    assertStringEquals("- (1 Jahre, 1 Monate und 3 Tage)", diff.toString(), "Diff between 03.01.2018 and 06.02.2019");

    diff = dateB.diffNormal(dateA);
    assertStringEquals("+ (1 Jahre, 1 Monate und 3 Tage)", diff.toString(), "Diff between 06.02.2019 and 03.01.2018");


    dateA = new CDate(6, 4, 2017);
    dateB = new CDate(6, 2, 2019);

    diff = dateA.diffNormal(dateB);
    assertStringEquals("- (1 Jahre, 10 Monate und 0 Tage)", diff.toString(), "Diff between 06.04.2017 and 06.02.2019");

    diff = dateB.diffNormal(dateA);
    assertStringEquals("+ (1 Jahre, 10 Monate und 0 Tage)", diff.toString(), "Diff between 06.02.2019 and 06.04.2017");


    dateA = new CDate(25, 4, 2018);
    dateB = new CDate(28, 2, 2015);

    diff = dateA.diffNormal(dateB);
    assertStringEquals("+ (3 Jahre, 1 Monate und 28 Tage)", diff.toString(), "Diff between 25.04.2018 and 28.02.2015");

    diff = dateB.diffNormal(dateA);
    assertStringEquals("- (3 Jahre, 1 Monate und 28 Tage)", diff.toString(), "Diff between 28.02.2015 and 25.04.2018");
  }

  /**
   * Checks that the "diff360" method works as expected.
   */
  private static void checkDiff360()
  {
    CDateDiff diff;
    CDate dateA, dateB;

    dateA = new CDate(2, 12, 2017);
    dateB = new CDate(1, 2, 2019);

    diff = dateA.diff360(dateB);
    assertStringEquals("- (1 Jahre, 1 Monate und 29 Tage)", diff.toString(), "Diff between 06.04.2017 and 06.02.2019");

    diff = dateB.diff360(dateA);
    assertStringEquals("+ (1 Jahre, 1 Monate und 29 Tage)", diff.toString(), "Diff between 06.02.2019 and 06.04.2017");
  }

  /**
   * Checks that the "getDayOfWeek" method works as expected.
   */
  private static void checkGetDayOfWeek()
  {
    CDate date;

    date = new CDate(14, 10, 2019);
    assertIntEquals(0, date.getDayOfWeek(), "14.10.2019 is Monday");

    date = new CDate(12, 4, 1956);
    assertIntEquals(3, date.getDayOfWeek(), "12.04.1956 is Thursday");
  }

  /**
   * Checks that the "isOfficialHoliday" method works as expected.
   */
  private static void checkIsOfficialHoliday()
  {
    CDate date;

    date = new CDate(1, 1, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "01.01.2019 is holiday");

    date = new CDate(6, 1, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "06.01.2019 is holiday");

    date = new CDate(8, 3, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "08.03.2019 is holiday");

    date = new CDate(19, 4, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "19.04.2019 is holiday");

    date = new CDate(21, 4, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "21.04.2019 is holiday");

    date = new CDate(22, 4, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "22.04.2019 is holiday");

    date = new CDate(1, 5, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "01.05.2019 is holiday");

    date = new CDate(30, 5, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "30.05.2019 is holiday");

    date = new CDate(9, 6, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "09.06.2019 is holiday");

    date = new CDate(10, 6, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "10.06.2019 is holiday");

    date = new CDate(20, 6, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "20.06.2019 is holiday");

    date = new CDate(8, 8, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "08.08.2019 is holiday");

    date = new CDate(15, 8, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "15.08.2019 is holiday");

    date = new CDate(3, 10, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "03.10.2019 is holiday");

    date = new CDate(31, 10, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "31.10.2019 is holiday");

    date = new CDate(1, 11, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "01.11.2019 is holiday");

    date = new CDate(20, 11, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "20.11.2019 is holiday");

    date = new CDate(25, 12, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "25.12.2019 is holiday");

    date = new CDate(26, 12, 2019);
    assertBoolEquals(true, date.isOfficialHoliday(), "26.12.2019 is holiday");


    // Some dates that are no holidays
    date = new CDate(1, 4, 2019);
    assertBoolEquals(false, date.isOfficialHoliday(), "01.04.2019 is no holiday");

    date = new CDate(2, 6, 2019);
    assertBoolEquals(false, date.isOfficialHoliday(), "02.06.2019 is no holiday");
  }

  /**
   * Checks that the "toFormattedString" method works as expected.
   */
  private static void checkToFormattedString()
  {
    CDate date;

    date = new CDate(2, 3, 2015);
    assertStringEquals("2.3.2015", date.toFormattedString("%d.%m.%y"), "02.03.2015 can be formatted");

    // Pad with zeros
    date = new CDate(4, 5, 2013);
    assertStringEquals("04.5.2013", date.toFormattedString("%d:00.%m.%y"), "04.05.2013 can be formatted");

    // Month name
    date = new CDate(7, 1, 2019);
    assertStringEquals("7.Jan 2019", date.toFormattedString("%d.%M %y"), "07.01.2019 can be formatted");

    date = new CDate(4, 6, 2002);
    assertStringEquals("4.Juni.2002", date.toFormattedString("%d.%F.%y"), "04.06.2002 can be formatted");
  }

  /**
   * Checks that the toJulianDate() method works as expected.
   */
  private static void checkToJulianDate()
  {
    // Using http://www.nabkal.de/kalrechJD.html results to test the toJulianDate() method
    CDate date;

    date = new CDate(17, 10, 2019);
    assertDoubleEquals(2458773.5, date.toJulianDate(), "17.10.2019 results in julian date 2458773.5");

    date = new CDate(13, 02, 1980);
    assertDoubleEquals(2444282.5, date.toJulianDate(), "13.02.1980 results in julian date 2444282.5");
  }
}
