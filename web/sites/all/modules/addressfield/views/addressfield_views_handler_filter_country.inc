<?php

class addressfield_views_handler_filter_country extends views_handler_filter_in_operator {
  function get_value_options() {
    $this->value_title = t('Country');
    $limit_countries = array();
    if ($this->options['expose']['reduce'] && !empty($this->options['value'])) {
      $limit_countries = $this->options['value'];
    }
    $this->value_options = _addressfield_country_options_list($limit_countries);
  }
}