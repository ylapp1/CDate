/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Util class that returns information about a month.
 */
public class MonthInfo
{
  /**
   * The list of full month names.
   *
   * @var fullMonthNames
   */
  private static string[] fullMonthNames = {
    "Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"
  };

  /**
   * The list of short month names.
   *
   * @var shortMonthNames
   */
  private static string[] shortMonthNames = {
    "Jan", "Feb", "Mär", "Apr", "Mai", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez"
  };


  /**
   * The month number for which this MonthInfo will provide information (0 = January, 11 = December)
   *
   * @var int month
   */
  private int month;


  /**
   * Constructs a new MonthInfo.
   *
   * @param _monthNumber The month number to provide information for
   */
  public MonthInfo(int _monthNumber)
  {
    month = _monthNumber - 1;
  }


  /**
   * Returns the full month name for the target month.
   *
   * @return string The full month name
   */
  public string getFullName()
  {
    return fullMonthNames[month];
  }

  /**
   * Returns the short month name for the target month.
   *
   * @return string The short month name
   */
  public string getShortName()
  {
    return shortMonthNames[month];
  }
}
