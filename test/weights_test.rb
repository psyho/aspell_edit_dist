require File.expand_path( File.dirname(__FILE__) + '/test_helper.rb' )

class WeightsTest < Test::Unit::TestCase

  def test_weights_defined
    assert defined?(Aspeller), "Aspeller module should be defined"
    assert defined?(Aspeller::EditDistanceWeights), "class Aspeller::EditDistanceWeights is supposed to be defined"
  end

  def test_weights_has_constructor
    assert_respond_to Aspeller::EditDistanceWeights, :new
  end

  WEIGHT_METHODS = [:del1, :del2, :swap, :sub, :similar, :min, :max]

  def test_weights_getters
    weights = Aspeller::EditDistanceWeights.new
    WEIGHT_METHODS.each do |method_name|
      assert_respond_to weights, method_name
      assert weights.send(method_name), "weights.#{method_name} should return something"
    end
  end

  def test_weights_default_values
    weights = Aspeller::EditDistanceWeights.new
    assert_equal 1, weights.del1
    assert_equal 1, weights.del2
    assert_equal 1, weights.swap
    assert_equal 1, weights.sub
    assert_equal 0, weights.similar
    assert_equal 1, weights.min
    assert_equal 1, weights.max
  end

  def test_weights_setters
    weights = Aspeller::EditDistanceWeights.new

    n = 123
    WEIGHT_METHODS.each do |method_name|
      setter_name = :"#{method_name}="

      assert_respond_to weights, setter_name

      weights.send(setter_name, n)
      assert_equal n, weights.send(method_name)

      n += 1
    end
  end

end