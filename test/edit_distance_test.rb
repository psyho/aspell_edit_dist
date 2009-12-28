require File.expand_path( File.dirname(__FILE__) + '/test_helper.rb' )

class EditDistanceTest < Test::Unit::TestCase

  def test_limit_distance_defined
    assert defined?(Aspeller), "module Aspell must be defined"
    assert defined?(Aspeller.limit_edit_distance), "method Aspell.limit_edit_distance must be defined"
  end

  def test_limit_distance_returns_fixnum
    result = Aspeller.limit_edit_distance("a", "b", 1, Aspeller::EditDistanceWeights.new)
    assert result.is_a?(Fixnum), "limit_edit_distance is supposed to return a fixnum"
  end

  def test_limit_distance_returns_right_value
    result = Aspeller.limit_edit_distance("test", "tast", 1, Aspeller::EditDistanceWeights.new)
    assert_equal 1, result
  end

  def test_limit_distance_uses_passed_weights
    weights = Aspeller::EditDistanceWeights.new
    weights.sub = 2
    result = Aspeller.limit_edit_distance("test", "tast", 1, weights)
    assert_equal 2, result
  end
end