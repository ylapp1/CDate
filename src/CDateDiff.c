/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

using System;

/**
 * Stores the result for a detailed date difference.
 */
public class CDateDiff
{
  /**
   * True if the date difference is negative (-), false if it is positive (+)
   * @var bool isNegative
   */
  private bool isNegative;

  /**
   * The number of days of the difference
   * @var int days
   */
  private int days;

  /**
   * The number of months of the difference
   * @var int months
   */
  private int months;

  /**
   * The number of years of the difference
   * @var int years
   */
  private int years;


  /**
   * Constructs a new CDateDiff.
   *
   * @param _isNegative True if the difference is negative, false if it is positive
   * @param _days The number of days
   * @param _months The number of months
   * @param _years The number of years
   */
  public CDateDiff(bool _isNegative, int _days, int _months, int _years)
  {
    isNegative = _isNegative;
    days = _days;
    months = _months;
    years = _years;
  }


  /**
   * Generates and returns a string from the information stored in this date difference.
   *
   * @return string The generated string
   */
  public string toString()
  {
    return String.Format("{0} ({1} Jahre, {2} Monate und {3} Tage)", isNegative ? "-" : "+", years, months, days);
  }
}
