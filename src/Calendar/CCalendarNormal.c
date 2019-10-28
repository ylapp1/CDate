/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Represents the normal 365 days calendar.
 */
public class CCalendarNormal: CCalendar
{
  /**
   * The list of days per month.
   * @var daysPerMonth
   */
  private static int[] daysPerMonth = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  /**
   * Returns the number of days in a specified month.
   *
   * @param _month The month number (0 = January, 11 = December)
   * @param _year The year number to check for leap year
   *
   * @return int The number of days in the month
   */
  public override int getNumberOfDaysInMonth(int _month, int _year)
  {
    if (_month == 1 && isLeapYear(_year))
    { // Special Case: It is February and it's a leap year
        return 29;
    }
    else return daysPerMonth[_month];
  }
}
