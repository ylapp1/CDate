/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

/**
 * Util class to fetch official holiday names for specified dates.
 */
abstract public class OfficialHolidays
{
  /**
   * Returns the offical holiday name for a specified date.
   * Will return an empty string if there is no official holiday on that date.
   *
   * @param _date The date to fetch the official holiday name for
   *
   * @return string The official holiday name
   */
  abstract public string getDayOfficialHolidayName(CDate _date);
}
