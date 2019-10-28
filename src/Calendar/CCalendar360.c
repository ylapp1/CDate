/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Represents the bank calendar with 30 days per month and 360 days per year.
 */
public class CCalendar360: CCalendar
{
  /**
   * Returns the number of days in a specified month.
   *
   * @param _month The month number (0 = January, 11 = December)
   * @param _year The year number to check for leap year
   *
   * @return int The number of days in the month
   */
  public override int getNumberOfDaysInMonth(int _month, int _year)
  { // Every month has 30 days in this calendar
    return 30;
  }
}
