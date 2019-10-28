/**
 * @file
 * @version 0.1
 * @copyright 2019 Yannick Lapp
 * @author Yannick Lapp <yannick.lapp@cn-consult.eu>
 */

using System;
using System.Text.RegularExpressions;

/**
 * Stores a date and provides various util methods to fetch information about the date and to compare it to other dates.
 */
public class CDate
{
  // Constants
  public const int COMPARESTATUS_LOWER_THAN_COMPARISON_DATE = 1;
  public const int COMPARESTATUS_EQUAL_TO_COMPARISON_DATE = 0;
  public const int COMPARESTATUS_HIGHER_THAN_COMPARISON_DATE = -1;

  // Available calendars
  private static CCalendarNormal calendarNormal = new CCalendarNormal();
  private static CCalendar360 calendar360 = new CCalendar360();

  // Available holidays
  private static GermanyOfficialHolidays germanyHolidays = new GermanyOfficialHolidays();


  // Information about the date
  private int day;
  private int month;
  private int year;


  /**
   * CDate constructor.
   *
   * @param _day The day number
   * @param _month The month number
   * @param _year The year number
   *
   * @throws Exception The Exception when the specified date is invalid
   */
  public CDate(int _day, int _month, int _year)
  {
    validateDate(_day - 1, _month - 1, _year);

    day = _day - 1;
    month = _month - 1;
    year = _year;
  }

  /**
   * Copy constructor.
   *
   * @param _date The date to copy
   */
  public CDate(CDate _date)
  {
    day = _date.day;
    month = _date.month;
    year = _date.year;
  }


  /**
   * Validates a date.
   *
   * @param _day The day number (0 - 30)
   * @param _month The month number (0 = January, 11 = December)
   * @param _year The year number
   *
   * @throws Exception The Exception when the specified date is invalid
   */
  private void validateDate(int _day, int _month, int _year)
  {
    if (_month < 0 || _month > 11) throw new Exception("Invalid month");
    else if (_day < 0) throw new Exception("Invalid day");
    else if (getNumberOfDaysExceededForMonthInCalendar(calendarNormal) > 0 && getNumberOfDaysExceededForMonthInCalendar(calendar360) > 0)
    {
      throw new Exception("This day is invalid for that month in all supported calendar types");
    }
  }

  /**
   * Returns the number of days by which the month of this date in a specified calendar is exceeded by this date's day.
   *
   * @param _calendar The calendar to check
   *
   * @return int The number of days by which the month is exceeded
   */
  private int getNumberOfDaysExceededForMonthInCalendar(CCalendar _calendar)
  {
    int dayDiff = day - _calendar.getNumberOfDaysInMonth(month, year);
    if (dayDiff > 0) return dayDiff;
    else return 0;
  }


  // Getters

  /**
   * Returns the day nubmer of this date.
   *
   * @return int The day number
   */
  public int dayNumber()
  {
    return day + 1;
  }

  /**
   * Returns the month number of this date.
   *
   * @return int The month number
   */
  public int monthNumber()
  {
    return month + 1;
  }

  /**
   * Returns the year number of this date.
   *
   * @return int The year number
   */
  public int yearNumber()
  {
    return year;
  }


  /**
   * Returns the comparison status to a different CDate.
   *
   * @param _otherDate The comparison date
   *
   * @return int The comparison status (one of the COMPARESTATUS_* constants)
   */
  public int compareTo(CDate _otherDate)
  {
    int yearDiff = _otherDate.year - year;
    if (yearDiff == 0)
    { // The year number is the same, check the month

      int monthDiff = _otherDate.month - month;
      if (monthDiff == 0)
      { // The month number is the same, check the day

        // Math.Sign returns the sign of the number (-1 = -, 0 = 0, +1 = +)
        int dayDiff = _otherDate.day - day;
        return Math.Sign(dayDiff);
      }
      else return Math.Sign(monthDiff);
    }
    else return Math.Sign(yearDiff);
  }


  /**
   * Adds a number of days to this CDate.
   *
   * @param _numberOfDays The number of days to add
   */
  public void addDays(int _numberOfDays)
  {
    day = day + _numberOfDays;

    int numberOfDaysExceededForMonth;
    do
    {
      numberOfDaysExceededForMonth = getNumberOfDaysExceededForMonthInCalendar(calendarNormal);
      if (numberOfDaysExceededForMonth > 0)
      {
        day = numberOfDaysExceededForMonth;
        addMonths(1);
      }
    }
    while (numberOfDaysExceededForMonth > 0);
  }

  /**
   * Adds a number of months to this CDate.
   *
   * @param _numberOfMonths The number of months to add
   */
  private void addMonths(int _numberOfMonths)
  {
    month += _numberOfMonths;

    year += (int)(month / 12);
    month = month % 12;
  }


  /**
   * Returns the difference to another date using the regular calendar.
   *
   * @param _otherDate The date to compare this date to
   *
   * @return CDateDiff The difference to the other date
   */
  public CDateDiff diffNormal(CDate _otherDate)
  {
    return diff(_otherDate, calendarNormal);
  }

  /**
   * Returns the difference to another date using the bank calendar.
   *
   * @param _otherDate The date to compare this date to
   *
   * @return CDateDiff The difference to the other date
   */
  public CDateDiff diff360(CDate _otherDate)
  {
    return diff(_otherDate, calendar360);
  }

  /**
   * Calculates and returns the difference to another date in a specified calendar.
   *
   * @param _otherDate The date to compare this date to
   * @param _calendar The calendar to use for the comparison
   *
   * @return CDateDiff The difference to the other date
   */
  private CDateDiff diff(CDate _otherDate, CCalendar _calendar)
  {
    // Base date is the lower one
    bool isNegativeDiff;
    CDate lowerDate;
    CDate higherDate;

    if (compareTo(_otherDate) == COMPARESTATUS_LOWER_THAN_COMPARISON_DATE)
    {
      lowerDate = this;
      higherDate = _otherDate;
      isNegativeDiff = true;
    }
    else
      { // Equal or bigger than comparison date
      lowerDate = _otherDate;
      higherDate = this;
      isNegativeDiff = false;
    }


    int yearDiff = higherDate.year - lowerDate.year;
    int monthDiff = higherDate.month - lowerDate.month;
    int dayDiff = higherDate.day - lowerDate.day;

    int targetMonth, targetYear, monthOffset = 0;

    // Normalize days
    while (dayDiff < 0)
    {
      monthDiff -= 1;

      targetMonth = lowerDate.monthNumber() + (monthOffset % 12);
      targetYear = lowerDate.year + (int)(monthOffset / 12);

      dayDiff += _calendar.getNumberOfDaysInMonth(targetMonth, targetYear);
      monthOffset++;
    }

    while (monthDiff < 0)
    {
      yearDiff -= 1;
      monthDiff += 12;
    }

    return new CDateDiff(isNegativeDiff, dayDiff, monthDiff, yearDiff);
  }


  /**
   * Returns the day of the week of this date.
   *
   * @return int The day of the week
   */
  public int getDayOfWeek()
  {
    int century = (int)(year / 100);
    int yearOfCentury = year % 100;

    int dayNumber = day + 1;

    // 1 = March, 2 = April, ...
    int monthNumber = (month - 2) + 1;
    while (monthNumber < 0) monthNumber += 12;

    /*
     * This formula was taken from https://de.wikipedia.org/wiki/Wochentagsberechnung#4._Allgemeing%C3%BCltige_Formel and
     * https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
     */
    int weekDayNumber = (dayNumber + (int)(2.6 * monthNumber - 0.2) + yearOfCentury + (int)(yearOfCentury / 4) + (int)(century / 4) - 2 * century) % 7;

    return weekDayNumber - 1;
  }


  /**
   * Returns whether this date is an official holiday.
   *
   * @return bool True if this date is an official holiday, false otherwise
   */
  public bool isOfficialHoliday()
  {
    return !String.Equals(germanyHolidays.getDayOfficialHolidayName(this), "");
  }


  /**
   * Returns this date as a formatted string.
   *
   * The following format specifiers are available:
   * - %d = day number
   * - %m = month number
   * - %y = year number
   * - %F = full month name
   * - %M = short month name
   *
   * You may add ":<zeroes>.<zeros>" to define by how many zeros the numbers must be padded (usage is the same as in String.Format output variable specifiers).
   *
   * @param _formatString The format string
   *
   * @return string The formatted date string
   */
  public string toFormattedString(string _formatString)
  {
    string formatString = Regex.Replace(_formatString, "%d:(\\d+)", "{0:$1}");
    formatString = Regex.Replace(formatString, "%m:(\\d+)", "{1:$1}");
    formatString = Regex.Replace(formatString, "%y:(\\d+)", "{2:$1}");

    MonthInfo monthInfo = new MonthInfo(monthNumber());
    if (formatString.Contains("%F"))
      { // Full month name
        formatString = formatString.Replace("%F", monthInfo.getFullName());
      }
    if (formatString.Contains("%M"))
    { // Short month name
      formatString = formatString.Replace("%M", monthInfo.getShortName());
    }

    formatString = formatString.Replace("%d", "{0}").Replace("%m", "{1}").Replace("%y", "{2}");

    return String.Format(formatString, dayNumber(), monthNumber(), year);
  }


  /**
   * Returns the julian date that equals this gregorian date.
   * Using the algorithm from here: https://de.wikipedia.org/wiki/Julianisches_Datum#Umrechnung_Kalenderdatum_%E2%86%92_JD
   *
   * @return double The julian date
   */
  public double toJulianDate()
  {
    int y, m;
    if (monthNumber() > 2)
    {
      y = year;
      m = monthNumber();
    }
    else
    {
      y = year - 1;
      m = monthNumber() + 12;
    }

    int d = dayNumber();
    int b = 2 - (int)Math.Floor((double)(y / 100)) + (int)Math.Floor((double)(y / 400));

    return Math.Floor((double)(365.25 * (y + 4716))) + Math.Floor((double)(30.6001 * (m + 1))) + d + b - 1524.5;
  }


  /**
   * Returns this date as a string in the format "DD.MM.YYYY".
   *
   * @return string This date as a string
   */
  public string toString()
  {
    return String.Format("{0:00}.{1:00}.{2:0000}", day + 1, month + 1, year);
  }
}
