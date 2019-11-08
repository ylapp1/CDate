/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Base class for calendars that provides methods to fetch information about months in specified years.
 *
 * Call isLeapYear() to check whether a specified year is a leap year or not
 * Call getNumberOfDaysInMonth() to fetch the number that the specified month has in the specified year
 */
abstract public class CCalendar
{
  /**
   * Returns whether a specified year is a leap year.
   *
   * @param _year The year to check
   *
   * @return bool True if the year is a leap year, false otherwise
   *
   * This function was taken from http://www.keentpoint.com/programming/examples/csharp/Program-To-Check-Leap-Year
   */
  public bool isLeapYear(int _year)
  {
    return (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0));
  }

  /**
   * Returns the number of days in a specified month.
   *
   * @param _month The month number (0 = January, 11 = December)
   * @param _year The year number to check for leap year
   *
   * @return int The number of days in the month
   */
  abstract public int getNumberOfDaysInMonth(int _month, int _year);
}
