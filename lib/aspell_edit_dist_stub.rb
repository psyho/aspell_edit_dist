raise "This file should never be required. It's here only for documentation purposes."

# module, through which the functionality of edit distance calculation is possible
module Aspeller

  # weights that are used by Aspell to determine edit distance between two strings
  class EditDistanceWeights

    # the cost of deleting a char in the first string, defaults to 1
    attr_accessor :del1

    # the cost of inserting a character or deleting a char in the next string, defaults to 1
    attr_accessor :del2

    # the cost of swapping two adjacent letters, defaults to 1
    attr_accessor :swap

    # the cost of replacing one letter with another, defaults to 1
    attr_accessor :sub

    # the cost of a "similar" but not exact match for two characters, defaults to 0
    attr_accessor :similar

    # the min of del1, del2, swap and sub, defaults to 1
    attr_accessor :min

    # the max of del1, del2, swap and sub, defaults to 1
    attr_accessor :max
    
  end

  # limit_edit_distance finds the shortest edit distance but will
  # stop and return a number at least as large as LARGE_NUM if it has
  # to do more edits than a set limit.
  # Note that this does NOT mean that the score returned is <= limit*w.max
  # as "sub" vs "submarine" will return 6*(cost of insertion) no matter what
  # the limit is.
  # The edit distance is
  # (cost of swap)(# of swaps) + (cost of deletion)(# of deletions)
  #   + (cost of insertion)(# of insertions)
  #   + (cost of substitutions)(# of substitutions)
  #
  # Preconditions:
  #   max(strlen(a), strlen(b))*max(of the edit weights) <= 2^15
  #     if violated than an incorrect result may be returned (which may be negative)
  #     due to overflow of a short integer
  #   (limit+1)*w.min < limit*w.max
  #   limit <= 5 (use edit_distance if limit > 5)
  # where w.min and w.max is the minimum and maximum cost of an edit
  # respectfully.
  #
  # The running time is asymptotically bounded above by
  # (3^l)*n where l is the limit and n is the maxium of strlen(a),strlen(b)
  # Based on my informal tests, however, the n does not really matter
  # and the running time is more like (3^l).
  #
  # limit_edit_distance, based on my informal tests, turns out to be
  # faster than edit_dist for l < 5.  For l == 5 it is about the
  # smaller for short strings (<= 5) and less than for longer strings
  def self.limit_edit_distance(strA, strB, limit, weights); end
end