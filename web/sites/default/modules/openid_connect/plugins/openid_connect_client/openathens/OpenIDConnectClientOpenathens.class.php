<?php

/**
 * @file
 * Open Athens OpenID Connect client.
 */

class OpenIDConnectClientOpenathens extends OpenIDConnectClientBase {

  /**
   * {@inheritdoc}
   */
  public function settingsForm() {
    $form = parent::settingsForm();

    $form['authorization_endpoint'] = array(
      '#title' => t('Authorization endpoint'),
      '#type' => 'textfield',
      '#default_value' => 'https://connect.openathens.net/oidc/auth',
    );
    $form['token_endpoint'] = array(
      '#title' => t('Token endpoint'),
      '#type' => 'textfield',
      '#default_value' => 'https://connect.openathens.net/oidc/token',
    );
    $form['userinfo_endpoint'] = array(
      '#title' => t('UserInfo endpoint'),
      '#type' => 'textfield',
      '#default_value' => 'https://connect.openathens.net/oidc/userinfo',
    );
    $form['subject_key'] = array(
      '#title' => t('Subject key'),
      '#type' => 'radios',
      '#options' => array('sub' => 'sub', 'eduPersonTargetedID' => 'eduPersonTargetedID'),
      '#default_value' => $this->getSetting('subject_key', 'eduPersonTargetedID'),
      '#description' => t('Choose which immutable access token key to use as the subject.'),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getEndpoints() {
    return array(
      'authorization' => $this->getSetting('authorization_endpoint'),
      'token' => $this->getSetting('token_endpoint'),
      'userinfo' => $this->getSetting('userinfo_endpoint'),
    );
  }
}
